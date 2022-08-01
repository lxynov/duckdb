#include "duckdb/planner/operator/logical_delim_get.hpp"

namespace duckdb {

void LogicalDelimGet::Serialize(FieldWriter &writer) const {
	writer.WriteField(table_index);
	writer.WriteRegularSerializableList(chunk_types);
}

unique_ptr<LogicalOperator> LogicalDelimGet::Deserialize(ClientContext &context, LogicalOperatorType type,
                                                         FieldReader &reader) {
	auto table_index = reader.ReadRequired<idx_t>();
	auto chunk_types = reader.ReadRequiredSerializableList<LogicalType, LogicalType>();
	return make_unique<LogicalDelimGet>(table_index, chunk_types);
}

} // namespace duckdb
