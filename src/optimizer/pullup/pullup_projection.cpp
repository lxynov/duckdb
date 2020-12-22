#include "duckdb/optimizer/filter_pullup.hpp"
#include "duckdb/planner/expression/bound_columnref_expression.hpp"
#include "duckdb/planner/expression_iterator.hpp"
#include "duckdb/planner/operator/logical_empty_result.hpp"
#include "duckdb/planner/operator/logical_projection.hpp"
#include "duckdb/planner/expression/bound_comparison_expression.hpp"

//TOREMOVE
#include<iostream>

namespace duckdb {
using namespace std;

static void RevertFilterPullup(LogicalProjection &proj, vector<unique_ptr<Expression>> &expressions) {
    unique_ptr<LogicalFilter> filter = make_unique<LogicalFilter>();
    for(idx_t i=0; i < expressions.size(); ++i) {
        filter->expressions.push_back(move(expressions[i]));
    }
    expressions.clear();
    filter->children.push_back(move(proj.children[0]));
    proj.children[0] = move(filter);
}

static void ReplaceExpressionBinding(vector<unique_ptr<Expression>> &proj_expressions, Expression &expr, idx_t proj_table_idx) {
    if (expr.type == ExpressionType::BOUND_COLUMN_REF) {
        bool found_proj_col = false;
        BoundColumnRefExpression &colref = (BoundColumnRefExpression &)expr;
        // find the corresponding column index in the projection expressions
        for(idx_t proj_idx=0; proj_idx < proj_expressions.size(); proj_idx++) {
            auto proj_expr = proj_expressions[proj_idx].get();
            if (proj_expr->type == ExpressionType::BOUND_COLUMN_REF) {
                if(colref.Equals(proj_expr)) {
                    colref.binding.table_index = proj_table_idx;
                    colref.binding.column_index = proj_idx;
                    found_proj_col = true;
                    break;
                }
            }
        }
        if(!found_proj_col) {
            //Project a new column
            auto new_colref = colref.Copy();
            colref.binding.table_index = proj_table_idx;
            colref.binding.column_index = proj_expressions.size();
            proj_expressions.push_back(move(new_colref));
        }
    }
    ExpressionIterator::EnumerateChildren(expr, [&](Expression &child) { return ReplaceExpressionBinding(proj_expressions, child, proj_table_idx); });
}

void FilterPullup::ProjectSetOperation(LogicalProjection &proj) {
    vector<unique_ptr<Expression>> copy_proj_expressions;
    //copying the project expressions, it's useful whether we should revert the filter pullup
    for(idx_t i=0; i < proj.expressions.size(); ++i) {
        copy_proj_expressions.push_back(proj.expressions[i]->Copy());
    }

    //Replace filter expression bindings, when need we add new columns into the copied projection expression
    vector<unique_ptr<Expression>> changed_filter_expressions;
    for(idx_t i=0; i < filters_expr_pullup.size(); ++i) {
        auto copy_filter_expr = filters_expr_pullup[i]->Copy();
        ReplaceExpressionBinding(copy_proj_expressions, (Expression &)*copy_filter_expr, proj.table_index);
        changed_filter_expressions.push_back(move(copy_filter_expr));
    }

    ///Case new columns were added into the projection
    //we must skip filter pullup because adding new columns to set operators might change the result
    if(copy_proj_expressions.size() > proj.expressions.size()) {
        RevertFilterPullup(proj, filters_expr_pullup);
        return;
    }

    //now we must replace the filter bindings
    D_ASSERT(filters_expr_pullup.size() == changed_filter_expressions.size());
    for(idx_t i=0; i < filters_expr_pullup.size(); ++i) {
        filters_expr_pullup[i] = move(changed_filter_expressions[i]);
    }
}

unique_ptr<LogicalOperator> FilterPullup::PullupProjection(unique_ptr<LogicalOperator> op) {
    D_ASSERT(op->type == LogicalOperatorType::LOGICAL_PROJECTION);
    op->children[0] = Rewrite(move(op->children[0]));
    if(filters_expr_pullup.size() > 0) {
        auto &proj = (LogicalProjection &)*op;
        if(is_set_operation) {
            //special treatment for projections from set operators
            ProjectSetOperation(proj);
            return op;
        }

        for(idx_t i=0; i < filters_expr_pullup.size(); ++i) {
            auto &expr = (Expression &)*filters_expr_pullup[i];
                ReplaceExpressionBinding(proj.expressions, expr, proj.table_index);
        }
    }
    return op;
}

} // namespace duckdb
