//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/format_serializer.hpp"
#include "duckdb/common/serializer/format_deserializer.hpp"
#include "duckdb/planner/operator/list.hpp"
#include "duckdb/catalog/catalog_entry/schema_catalog_entry.hpp"
#include "duckdb/catalog/catalog_entry/table_catalog_entry.hpp"

namespace duckdb {

void LogicalOperator::FormatSerialize(FormatSerializer &serializer) const {
	serializer.WriteProperty(100, "type", type);
	serializer.WriteProperty(101, "children", children);
}

unique_ptr<LogicalOperator> LogicalOperator::FormatDeserialize(FormatDeserializer &deserializer) {
	auto type = deserializer.ReadProperty<LogicalOperatorType>(100, "type");
	auto children = deserializer.ReadProperty<vector<unique_ptr<LogicalOperator>>>(101, "children");
	deserializer.Set<LogicalOperatorType>(type);
	unique_ptr<LogicalOperator> result;
	switch (type) {
	case LogicalOperatorType::LOGICAL_AGGREGATE_AND_GROUP_BY:
		result = LogicalAggregate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_ALTER:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_ANY_JOIN:
		result = LogicalAnyJoin::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_ASOF_JOIN:
		result = LogicalComparisonJoin::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_ATTACH:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CHUNK_GET:
		result = LogicalColumnDataGet::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_COMPARISON_JOIN:
		result = LogicalComparisonJoin::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_COPY_TO_FILE:
		result = LogicalCopyToFile::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_INDEX:
		result = LogicalCreateIndex::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_MACRO:
		result = LogicalCreate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_SCHEMA:
		result = LogicalCreate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_SEQUENCE:
		result = LogicalCreate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_TABLE:
		result = LogicalCreateTable::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_TYPE:
		result = LogicalCreate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CREATE_VIEW:
		result = LogicalCreate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CROSS_PRODUCT:
		result = LogicalCrossProduct::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_CTE_REF:
		result = LogicalCTERef::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DELETE:
		result = LogicalDelete::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DELIM_GET:
		result = LogicalDelimGet::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DELIM_JOIN:
		result = LogicalComparisonJoin::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DETACH:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DISTINCT:
		result = LogicalDistinct::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DROP:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_DUMMY_SCAN:
		result = LogicalDummyScan::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_EMPTY_RESULT:
		result = LogicalEmptyResult::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_EXCEPT:
		result = LogicalSetOperation::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_EXPLAIN:
		result = LogicalExplain::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_EXPRESSION_GET:
		result = LogicalExpressionGet::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_EXTENSION_OPERATOR:
		result = LogicalExtensionOperator::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_FILTER:
		result = LogicalFilter::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_GET:
		result = LogicalGet::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_INSERT:
		result = LogicalInsert::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_INTERSECT:
		result = LogicalSetOperation::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_LIMIT:
		result = LogicalLimit::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_LIMIT_PERCENT:
		result = LogicalLimitPercent::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_LOAD:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_MATERIALIZED_CTE:
		result = LogicalMaterializedCTE::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_ORDER_BY:
		result = LogicalOrder::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_PIVOT:
		result = LogicalPivot::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_POSITIONAL_JOIN:
		result = LogicalPositionalJoin::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_PROJECTION:
		result = LogicalProjection::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_RECURSIVE_CTE:
		result = LogicalRecursiveCTE::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_RESET:
		result = LogicalReset::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_SAMPLE:
		result = LogicalSample::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_SET:
		result = LogicalSet::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_SHOW:
		result = LogicalShow::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_TOP_N:
		result = LogicalTopN::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_TRANSACTION:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_UNION:
		result = LogicalSetOperation::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_UNNEST:
		result = LogicalUnnest::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_UPDATE:
		result = LogicalUpdate::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_VACUUM:
		result = LogicalSimple::FormatDeserialize(deserializer);
		break;
	case LogicalOperatorType::LOGICAL_WINDOW:
		result = LogicalWindow::FormatDeserialize(deserializer);
		break;
	default:
		throw SerializationException("Unsupported type for deserialization of LogicalOperator!");
	}
	deserializer.Unset<LogicalOperatorType>();
	result->children = std::move(children);
	return result;
}

void LogicalAggregate::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "expressions", expressions);
	serializer.WriteProperty(201, "group_index", group_index);
	serializer.WriteProperty(202, "aggregate_index", aggregate_index);
	serializer.WriteProperty(203, "groupings_index", groupings_index);
	serializer.WriteProperty(204, "groups", groups);
	serializer.WriteProperty(205, "grouping_sets", grouping_sets);
	serializer.WriteProperty(206, "grouping_functions", grouping_functions);
}

unique_ptr<LogicalOperator> LogicalAggregate::FormatDeserialize(FormatDeserializer &deserializer) {
	auto expressions = deserializer.ReadProperty<vector<unique_ptr<Expression>>>(200, "expressions");
	auto group_index = deserializer.ReadProperty<idx_t>(201, "group_index");
	auto aggregate_index = deserializer.ReadProperty<idx_t>(202, "aggregate_index");
	auto result = duckdb::unique_ptr<LogicalAggregate>(new LogicalAggregate(group_index, aggregate_index, std::move(expressions)));
	deserializer.ReadProperty(203, "groupings_index", result->groupings_index);
	deserializer.ReadProperty(204, "groups", result->groups);
	deserializer.ReadProperty(205, "grouping_sets", result->grouping_sets);
	deserializer.ReadProperty(206, "grouping_functions", result->grouping_functions);
	return std::move(result);
}

void LogicalAnyJoin::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "join_type", join_type);
	serializer.WriteProperty(201, "mark_index", mark_index);
	serializer.WriteProperty(202, "left_projection_map", left_projection_map);
	serializer.WriteProperty(203, "right_projection_map", right_projection_map);
	serializer.WriteProperty(204, "condition", *condition);
}

unique_ptr<LogicalOperator> LogicalAnyJoin::FormatDeserialize(FormatDeserializer &deserializer) {
	auto join_type = deserializer.ReadProperty<JoinType>(200, "join_type");
	auto result = duckdb::unique_ptr<LogicalAnyJoin>(new LogicalAnyJoin(join_type));
	deserializer.ReadProperty(201, "mark_index", result->mark_index);
	deserializer.ReadProperty(202, "left_projection_map", result->left_projection_map);
	deserializer.ReadProperty(203, "right_projection_map", result->right_projection_map);
	deserializer.ReadProperty(204, "condition", result->condition);
	return std::move(result);
}

void LogicalCTERef::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "cte_index", cte_index);
	serializer.WriteProperty(202, "chunk_types", chunk_types);
	serializer.WriteProperty(203, "bound_columns", bound_columns);
	serializer.WriteProperty(204, "materialized_cte", materialized_cte);
}

unique_ptr<LogicalOperator> LogicalCTERef::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto cte_index = deserializer.ReadProperty<idx_t>(201, "cte_index");
	auto chunk_types = deserializer.ReadProperty<vector<LogicalType>>(202, "chunk_types");
	auto bound_columns = deserializer.ReadProperty<vector<string>>(203, "bound_columns");
	auto materialized_cte = deserializer.ReadProperty<CTEMaterialize>(204, "materialized_cte");
	auto result = duckdb::unique_ptr<LogicalCTERef>(new LogicalCTERef(table_index, cte_index, std::move(chunk_types), std::move(bound_columns), materialized_cte));
	return std::move(result);
}

void LogicalColumnDataGet::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "chunk_types", chunk_types);
	serializer.WriteProperty(202, "collection", *collection);
}

unique_ptr<LogicalOperator> LogicalColumnDataGet::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto chunk_types = deserializer.ReadProperty<vector<LogicalType>>(201, "chunk_types");
	auto collection = deserializer.ReadProperty<unique_ptr<ColumnDataCollection>>(202, "collection");
	auto result = duckdb::unique_ptr<LogicalColumnDataGet>(new LogicalColumnDataGet(table_index, std::move(chunk_types), std::move(collection)));
	return std::move(result);
}

void LogicalComparisonJoin::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "join_type", join_type);
	serializer.WriteProperty(201, "mark_index", mark_index);
	serializer.WriteProperty(202, "left_projection_map", left_projection_map);
	serializer.WriteProperty(203, "right_projection_map", right_projection_map);
	serializer.WriteProperty(204, "conditions", conditions);
	serializer.WriteProperty(205, "mark_types", mark_types);
	serializer.WriteProperty(206, "duplicate_eliminated_columns", duplicate_eliminated_columns);
}

unique_ptr<LogicalOperator> LogicalComparisonJoin::FormatDeserialize(FormatDeserializer &deserializer) {
	auto join_type = deserializer.ReadProperty<JoinType>(200, "join_type");
	auto result = duckdb::unique_ptr<LogicalComparisonJoin>(new LogicalComparisonJoin(join_type, deserializer.Get<LogicalOperatorType>()));
	deserializer.ReadProperty(201, "mark_index", result->mark_index);
	deserializer.ReadProperty(202, "left_projection_map", result->left_projection_map);
	deserializer.ReadProperty(203, "right_projection_map", result->right_projection_map);
	deserializer.ReadProperty(204, "conditions", result->conditions);
	deserializer.ReadProperty(205, "mark_types", result->mark_types);
	deserializer.ReadProperty(206, "duplicate_eliminated_columns", result->duplicate_eliminated_columns);
	return std::move(result);
}

void LogicalCreate::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "info", *info);
}

unique_ptr<LogicalOperator> LogicalCreate::FormatDeserialize(FormatDeserializer &deserializer) {
	auto info = deserializer.ReadProperty<unique_ptr<CreateInfo>>(200, "info");
	auto result = duckdb::unique_ptr<LogicalCreate>(new LogicalCreate(deserializer.Get<LogicalOperatorType>(), deserializer.Get<ClientContext &>(), std::move(info)));
	return std::move(result);
}

void LogicalCreateIndex::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "info", *info);
	serializer.WriteProperty(201, "unbound_expressions", unbound_expressions);
}

unique_ptr<LogicalOperator> LogicalCreateIndex::FormatDeserialize(FormatDeserializer &deserializer) {
	auto info = deserializer.ReadProperty<unique_ptr<CreateInfo>>(200, "info");
	auto unbound_expressions = deserializer.ReadProperty<vector<unique_ptr<Expression>>>(201, "unbound_expressions");
	auto result = duckdb::unique_ptr<LogicalCreateIndex>(new LogicalCreateIndex(deserializer.Get<ClientContext &>(), std::move(info), std::move(unbound_expressions)));
	return std::move(result);
}

void LogicalCreateTable::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "catalog", schema.ParentCatalog().GetName());
	serializer.WriteProperty(201, "schema", schema.name);
	serializer.WriteProperty(202, "info", *info->base);
}

unique_ptr<LogicalOperator> LogicalCreateTable::FormatDeserialize(FormatDeserializer &deserializer) {
	auto catalog = deserializer.ReadProperty<string>(200, "catalog");
	auto schema = deserializer.ReadProperty<string>(201, "schema");
	auto info = deserializer.ReadProperty<unique_ptr<CreateInfo>>(202, "info");
	auto result = duckdb::unique_ptr<LogicalCreateTable>(new LogicalCreateTable(deserializer.Get<ClientContext &>(), catalog, schema, std::move(info)));
	return std::move(result);
}

void LogicalCrossProduct::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
}

unique_ptr<LogicalOperator> LogicalCrossProduct::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalCrossProduct>(new LogicalCrossProduct());
	return std::move(result);
}

void LogicalDelete::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "catalog", table.ParentCatalog().GetName());
	serializer.WriteProperty(201, "schema", table.ParentSchema().name);
	serializer.WriteProperty(202, "table", table.name);
	serializer.WriteProperty(203, "table_index", table_index);
	serializer.WriteProperty(204, "return_chunk", return_chunk);
	serializer.WriteProperty(205, "expressions", expressions);
}

unique_ptr<LogicalOperator> LogicalDelete::FormatDeserialize(FormatDeserializer &deserializer) {
	auto catalog = deserializer.ReadProperty<string>(200, "catalog");
	auto schema = deserializer.ReadProperty<string>(201, "schema");
	auto table = deserializer.ReadProperty<string>(202, "table");
	auto result = duckdb::unique_ptr<LogicalDelete>(new LogicalDelete(deserializer.Get<ClientContext &>(), catalog, schema, table));
	deserializer.ReadProperty(203, "table_index", result->table_index);
	deserializer.ReadProperty(204, "return_chunk", result->return_chunk);
	deserializer.ReadProperty(205, "expressions", result->expressions);
	return std::move(result);
}

void LogicalDelimGet::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "chunk_types", chunk_types);
}

unique_ptr<LogicalOperator> LogicalDelimGet::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto chunk_types = deserializer.ReadProperty<vector<LogicalType>>(201, "chunk_types");
	auto result = duckdb::unique_ptr<LogicalDelimGet>(new LogicalDelimGet(table_index, std::move(chunk_types)));
	return std::move(result);
}

void LogicalDistinct::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "distinct_type", distinct_type);
	serializer.WriteProperty(201, "distinct_targets", distinct_targets);
	serializer.WritePropertyWithDefault(202, "order_by", order_by, unique_ptr<BoundOrderModifier>());
}

unique_ptr<LogicalOperator> LogicalDistinct::FormatDeserialize(FormatDeserializer &deserializer) {
	auto distinct_type = deserializer.ReadProperty<DistinctType>(200, "distinct_type");
	auto distinct_targets = deserializer.ReadProperty<vector<unique_ptr<Expression>>>(201, "distinct_targets");
	auto result = duckdb::unique_ptr<LogicalDistinct>(new LogicalDistinct(std::move(distinct_targets), distinct_type));
	deserializer.ReadPropertyWithDefault(202, "order_by", result->order_by, unique_ptr<BoundOrderModifier>());
	return std::move(result);
}

void LogicalDummyScan::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
}

unique_ptr<LogicalOperator> LogicalDummyScan::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto result = duckdb::unique_ptr<LogicalDummyScan>(new LogicalDummyScan(table_index));
	return std::move(result);
}

void LogicalEmptyResult::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "return_types", return_types);
	serializer.WriteProperty(201, "bindings", bindings);
}

unique_ptr<LogicalOperator> LogicalEmptyResult::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalEmptyResult>(new LogicalEmptyResult());
	deserializer.ReadProperty(200, "return_types", result->return_types);
	deserializer.ReadProperty(201, "bindings", result->bindings);
	return std::move(result);
}

void LogicalExplain::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "explain_type", explain_type);
	serializer.WriteProperty(201, "physical_plan", physical_plan);
	serializer.WriteProperty(202, "logical_plan_unopt", logical_plan_unopt);
	serializer.WriteProperty(203, "logical_plan_opt", logical_plan_opt);
}

unique_ptr<LogicalOperator> LogicalExplain::FormatDeserialize(FormatDeserializer &deserializer) {
	auto explain_type = deserializer.ReadProperty<ExplainType>(200, "explain_type");
	auto result = duckdb::unique_ptr<LogicalExplain>(new LogicalExplain(explain_type));
	deserializer.ReadProperty(201, "physical_plan", result->physical_plan);
	deserializer.ReadProperty(202, "logical_plan_unopt", result->logical_plan_unopt);
	deserializer.ReadProperty(203, "logical_plan_opt", result->logical_plan_opt);
	return std::move(result);
}

void LogicalExpressionGet::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "expr_types", expr_types);
	serializer.WriteProperty(202, "expressions", expressions);
}

unique_ptr<LogicalOperator> LogicalExpressionGet::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto expr_types = deserializer.ReadProperty<vector<LogicalType>>(201, "expr_types");
	auto expressions = deserializer.ReadProperty<vector<vector<unique_ptr<Expression>>>>(202, "expressions");
	auto result = duckdb::unique_ptr<LogicalExpressionGet>(new LogicalExpressionGet(table_index, std::move(expr_types), std::move(expressions)));
	return std::move(result);
}

void LogicalFilter::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "expressions", expressions);
	serializer.WriteProperty(201, "projection_map", projection_map);
}

unique_ptr<LogicalOperator> LogicalFilter::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalFilter>(new LogicalFilter());
	deserializer.ReadProperty(200, "expressions", result->expressions);
	deserializer.ReadProperty(201, "projection_map", result->projection_map);
	return std::move(result);
}

void LogicalInsert::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "catalog", table.ParentCatalog().GetName());
	serializer.WriteProperty(201, "schema", table.ParentSchema().name);
	serializer.WriteProperty(202, "table", table.name);
	serializer.WriteProperty(203, "insert_values", insert_values);
	serializer.WriteProperty(204, "column_index_map", column_index_map);
	serializer.WriteProperty(205, "expected_types", expected_types);
	serializer.WriteProperty(206, "table_index", table_index);
	serializer.WriteProperty(207, "return_chunk", return_chunk);
	serializer.WriteProperty(208, "bound_defaults", bound_defaults);
	serializer.WriteProperty(209, "action_type", action_type);
	serializer.WriteProperty(210, "expected_set_types", expected_set_types);
	serializer.WriteProperty(211, "on_conflict_filter", on_conflict_filter);
	serializer.WritePropertyWithDefault(212, "on_conflict_condition", on_conflict_condition, unique_ptr<Expression>());
	serializer.WritePropertyWithDefault(213, "do_update_condition", do_update_condition, unique_ptr<Expression>());
	serializer.WriteProperty(214, "set_columns", set_columns);
	serializer.WriteProperty(215, "set_types", set_types);
	serializer.WriteProperty(216, "excluded_table_index", excluded_table_index);
	serializer.WriteProperty(217, "columns_to_fetch", columns_to_fetch);
	serializer.WriteProperty(218, "source_columns", source_columns);
}

unique_ptr<LogicalOperator> LogicalInsert::FormatDeserialize(FormatDeserializer &deserializer) {
	auto catalog = deserializer.ReadProperty<string>(200, "catalog");
	auto schema = deserializer.ReadProperty<string>(201, "schema");
	auto table = deserializer.ReadProperty<string>(202, "table");
	auto result = duckdb::unique_ptr<LogicalInsert>(new LogicalInsert(deserializer.Get<ClientContext &>(), catalog, schema, table));
	deserializer.ReadProperty(203, "insert_values", result->insert_values);
	deserializer.ReadProperty(204, "column_index_map", result->column_index_map);
	deserializer.ReadProperty(205, "expected_types", result->expected_types);
	deserializer.ReadProperty(206, "table_index", result->table_index);
	deserializer.ReadProperty(207, "return_chunk", result->return_chunk);
	deserializer.ReadProperty(208, "bound_defaults", result->bound_defaults);
	deserializer.ReadProperty(209, "action_type", result->action_type);
	deserializer.ReadProperty(210, "expected_set_types", result->expected_set_types);
	deserializer.ReadProperty(211, "on_conflict_filter", result->on_conflict_filter);
	deserializer.ReadPropertyWithDefault(212, "on_conflict_condition", result->on_conflict_condition, unique_ptr<Expression>());
	deserializer.ReadPropertyWithDefault(213, "do_update_condition", result->do_update_condition, unique_ptr<Expression>());
	deserializer.ReadProperty(214, "set_columns", result->set_columns);
	deserializer.ReadProperty(215, "set_types", result->set_types);
	deserializer.ReadProperty(216, "excluded_table_index", result->excluded_table_index);
	deserializer.ReadProperty(217, "columns_to_fetch", result->columns_to_fetch);
	deserializer.ReadProperty(218, "source_columns", result->source_columns);
	return std::move(result);
}

void LogicalLimit::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "limit_val", limit_val);
	serializer.WriteProperty(201, "offset_val", offset_val);
	serializer.WritePropertyWithDefault(202, "limit", limit, unique_ptr<Expression>());
	serializer.WritePropertyWithDefault(203, "offset", offset, unique_ptr<Expression>());
}

unique_ptr<LogicalOperator> LogicalLimit::FormatDeserialize(FormatDeserializer &deserializer) {
	auto limit_val = deserializer.ReadProperty<int64_t>(200, "limit_val");
	auto offset_val = deserializer.ReadProperty<int64_t>(201, "offset_val");
	auto limit = deserializer.ReadPropertyWithDefault<unique_ptr<Expression>>(202, "limit", unique_ptr<Expression>());
	auto offset = deserializer.ReadPropertyWithDefault<unique_ptr<Expression>>(203, "offset", unique_ptr<Expression>());
	auto result = duckdb::unique_ptr<LogicalLimit>(new LogicalLimit(limit_val, offset_val, std::move(limit), std::move(offset)));
	return std::move(result);
}

void LogicalLimitPercent::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "limit_percent", limit_percent);
	serializer.WriteProperty(201, "offset_val", offset_val);
	serializer.WritePropertyWithDefault(202, "limit", limit, unique_ptr<Expression>());
	serializer.WritePropertyWithDefault(203, "offset", offset, unique_ptr<Expression>());
}

unique_ptr<LogicalOperator> LogicalLimitPercent::FormatDeserialize(FormatDeserializer &deserializer) {
	auto limit_percent = deserializer.ReadProperty<double>(200, "limit_percent");
	auto offset_val = deserializer.ReadProperty<int64_t>(201, "offset_val");
	auto limit = deserializer.ReadPropertyWithDefault<unique_ptr<Expression>>(202, "limit", unique_ptr<Expression>());
	auto offset = deserializer.ReadPropertyWithDefault<unique_ptr<Expression>>(203, "offset", unique_ptr<Expression>());
	auto result = duckdb::unique_ptr<LogicalLimitPercent>(new LogicalLimitPercent(limit_percent, offset_val, std::move(limit), std::move(offset)));
	return std::move(result);
}

void LogicalMaterializedCTE::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "column_count", column_count);
	serializer.WriteProperty(202, "ctename", ctename);
}

unique_ptr<LogicalOperator> LogicalMaterializedCTE::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalMaterializedCTE>(new LogicalMaterializedCTE());
	deserializer.ReadProperty(200, "table_index", result->table_index);
	deserializer.ReadProperty(201, "column_count", result->column_count);
	deserializer.ReadProperty(202, "ctename", result->ctename);
	return std::move(result);
}

void LogicalOrder::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "orders", orders);
	serializer.WriteProperty(201, "projections", projections);
}

unique_ptr<LogicalOperator> LogicalOrder::FormatDeserialize(FormatDeserializer &deserializer) {
	auto orders = deserializer.ReadProperty<vector<BoundOrderByNode>>(200, "orders");
	auto result = duckdb::unique_ptr<LogicalOrder>(new LogicalOrder(std::move(orders)));
	deserializer.ReadProperty(201, "projections", result->projections);
	return std::move(result);
}

void LogicalPivot::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "pivot_index", pivot_index);
	serializer.WriteProperty(201, "bound_pivot", bound_pivot);
}

unique_ptr<LogicalOperator> LogicalPivot::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalPivot>(new LogicalPivot());
	deserializer.ReadProperty(200, "pivot_index", result->pivot_index);
	deserializer.ReadProperty(201, "bound_pivot", result->bound_pivot);
	return std::move(result);
}

void LogicalPositionalJoin::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
}

unique_ptr<LogicalOperator> LogicalPositionalJoin::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalPositionalJoin>(new LogicalPositionalJoin());
	return std::move(result);
}

void LogicalProjection::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "expressions", expressions);
}

unique_ptr<LogicalOperator> LogicalProjection::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto expressions = deserializer.ReadProperty<vector<unique_ptr<Expression>>>(201, "expressions");
	auto result = duckdb::unique_ptr<LogicalProjection>(new LogicalProjection(table_index, std::move(expressions)));
	return std::move(result);
}

void LogicalRecursiveCTE::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "union_all", union_all);
	serializer.WriteProperty(201, "ctename", ctename);
	serializer.WriteProperty(202, "table_index", table_index);
	serializer.WriteProperty(203, "column_count", column_count);
}

unique_ptr<LogicalOperator> LogicalRecursiveCTE::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalRecursiveCTE>(new LogicalRecursiveCTE());
	deserializer.ReadProperty(200, "union_all", result->union_all);
	deserializer.ReadProperty(201, "ctename", result->ctename);
	deserializer.ReadProperty(202, "table_index", result->table_index);
	deserializer.ReadProperty(203, "column_count", result->column_count);
	return std::move(result);
}

void LogicalReset::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "name", name);
	serializer.WriteProperty(201, "scope", scope);
}

unique_ptr<LogicalOperator> LogicalReset::FormatDeserialize(FormatDeserializer &deserializer) {
	auto name = deserializer.ReadProperty<string>(200, "name");
	auto scope = deserializer.ReadProperty<SetScope>(201, "scope");
	auto result = duckdb::unique_ptr<LogicalReset>(new LogicalReset(std::move(name), scope));
	return std::move(result);
}

void LogicalSample::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "sample_options", sample_options);
}

unique_ptr<LogicalOperator> LogicalSample::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalSample>(new LogicalSample());
	deserializer.ReadProperty(200, "sample_options", result->sample_options);
	return std::move(result);
}

void LogicalSet::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "name", name);
	serializer.WriteProperty(201, "value", value);
	serializer.WriteProperty(202, "scope", scope);
}

unique_ptr<LogicalOperator> LogicalSet::FormatDeserialize(FormatDeserializer &deserializer) {
	auto name = deserializer.ReadProperty<string>(200, "name");
	auto value = deserializer.ReadProperty<Value>(201, "value");
	auto scope = deserializer.ReadProperty<SetScope>(202, "scope");
	auto result = duckdb::unique_ptr<LogicalSet>(new LogicalSet(std::move(name), value, scope));
	return std::move(result);
}

void LogicalSetOperation::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "table_index", table_index);
	serializer.WriteProperty(201, "column_count", column_count);
}

unique_ptr<LogicalOperator> LogicalSetOperation::FormatDeserialize(FormatDeserializer &deserializer) {
	auto table_index = deserializer.ReadProperty<idx_t>(200, "table_index");
	auto column_count = deserializer.ReadProperty<idx_t>(201, "column_count");
	auto result = duckdb::unique_ptr<LogicalSetOperation>(new LogicalSetOperation(table_index, column_count, deserializer.Get<LogicalOperatorType>()));
	return std::move(result);
}

void LogicalShow::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "types_select", types_select);
	serializer.WriteProperty(201, "aliases", aliases);
}

unique_ptr<LogicalOperator> LogicalShow::FormatDeserialize(FormatDeserializer &deserializer) {
	auto result = duckdb::unique_ptr<LogicalShow>(new LogicalShow());
	deserializer.ReadProperty(200, "types_select", result->types_select);
	deserializer.ReadProperty(201, "aliases", result->aliases);
	return std::move(result);
}

void LogicalSimple::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "info", *info);
}

unique_ptr<LogicalOperator> LogicalSimple::FormatDeserialize(FormatDeserializer &deserializer) {
	auto info = deserializer.ReadProperty<unique_ptr<ParseInfo>>(200, "info");
	auto result = duckdb::unique_ptr<LogicalSimple>(new LogicalSimple(deserializer.Get<LogicalOperatorType>(), std::move(info)));
	return std::move(result);
}

void LogicalTopN::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "orders", orders);
	serializer.WriteProperty(201, "limit", limit);
	serializer.WriteProperty(202, "offset", offset);
}

unique_ptr<LogicalOperator> LogicalTopN::FormatDeserialize(FormatDeserializer &deserializer) {
	auto orders = deserializer.ReadProperty<vector<BoundOrderByNode>>(200, "orders");
	auto limit = deserializer.ReadProperty<idx_t>(201, "limit");
	auto offset = deserializer.ReadProperty<idx_t>(202, "offset");
	auto result = duckdb::unique_ptr<LogicalTopN>(new LogicalTopN(std::move(orders), limit, offset));
	return std::move(result);
}

void LogicalUnnest::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "unnest_index", unnest_index);
	serializer.WriteProperty(201, "expressions", expressions);
}

unique_ptr<LogicalOperator> LogicalUnnest::FormatDeserialize(FormatDeserializer &deserializer) {
	auto unnest_index = deserializer.ReadProperty<idx_t>(200, "unnest_index");
	auto result = duckdb::unique_ptr<LogicalUnnest>(new LogicalUnnest(unnest_index));
	deserializer.ReadProperty(201, "expressions", result->expressions);
	return std::move(result);
}

void LogicalUpdate::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "catalog", table.ParentCatalog().GetName());
	serializer.WriteProperty(201, "schema", table.ParentSchema().name);
	serializer.WriteProperty(202, "table", table.name);
	serializer.WriteProperty(203, "table_index", table_index);
	serializer.WriteProperty(204, "return_chunk", return_chunk);
	serializer.WriteProperty(205, "expressions", expressions);
	serializer.WriteProperty(206, "columns", columns);
	serializer.WriteProperty(207, "bound_defaults", bound_defaults);
	serializer.WriteProperty(208, "update_is_del_and_insert", update_is_del_and_insert);
}

unique_ptr<LogicalOperator> LogicalUpdate::FormatDeserialize(FormatDeserializer &deserializer) {
	auto catalog = deserializer.ReadProperty<string>(200, "catalog");
	auto schema = deserializer.ReadProperty<string>(201, "schema");
	auto table = deserializer.ReadProperty<string>(202, "table");
	auto result = duckdb::unique_ptr<LogicalUpdate>(new LogicalUpdate(deserializer.Get<ClientContext &>(), catalog, schema, table));
	deserializer.ReadProperty(203, "table_index", result->table_index);
	deserializer.ReadProperty(204, "return_chunk", result->return_chunk);
	deserializer.ReadProperty(205, "expressions", result->expressions);
	deserializer.ReadProperty(206, "columns", result->columns);
	deserializer.ReadProperty(207, "bound_defaults", result->bound_defaults);
	deserializer.ReadProperty(208, "update_is_del_and_insert", result->update_is_del_and_insert);
	return std::move(result);
}

void LogicalWindow::FormatSerialize(FormatSerializer &serializer) const {
	LogicalOperator::FormatSerialize(serializer);
	serializer.WriteProperty(200, "window_index", window_index);
	serializer.WriteProperty(201, "expressions", expressions);
}

unique_ptr<LogicalOperator> LogicalWindow::FormatDeserialize(FormatDeserializer &deserializer) {
	auto window_index = deserializer.ReadProperty<idx_t>(200, "window_index");
	auto result = duckdb::unique_ptr<LogicalWindow>(new LogicalWindow(window_index));
	deserializer.ReadProperty(201, "expressions", result->expressions);
	return std::move(result);
}

} // namespace duckdb
