//===----------------------------------------------------------------------===//
// This file is automatically generated by scripts/generate_serialization.py
// Do not edit this file manually, your changes will be overwritten
//===----------------------------------------------------------------------===//

#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"
#include "parquet_reader.hpp"

namespace duckdb {

void ParquetOptions::Serialize(Serializer &serializer) const {
	serializer.WritePropertyWithDefault<bool>(100, "binary_as_string", binary_as_string);
	serializer.WritePropertyWithDefault<bool>(101, "file_row_number", file_row_number);
	serializer.WriteProperty<MultiFileReaderOptions>(102, "file_options", file_options);
}

ParquetOptions ParquetOptions::Deserialize(Deserializer &deserializer) {
	ParquetOptions result;
	deserializer.ReadPropertyWithDefault<bool>(100, "binary_as_string", result.binary_as_string);
	deserializer.ReadPropertyWithDefault<bool>(101, "file_row_number", result.file_row_number);
	deserializer.ReadProperty<MultiFileReaderOptions>(102, "file_options", result.file_options);
	return result;
}

} // namespace duckdb
