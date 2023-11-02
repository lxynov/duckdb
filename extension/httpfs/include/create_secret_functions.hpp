#pragma once

#include "duckdb.hpp"

namespace duckdb {
class CreateSecretInput;
class CreateSecretFunction;
class S3AuthParams;

struct CreateS3SecretFunctions {
public:
	//! Register all CreateSecretFunctions
	static void Register(DatabaseInstance &instance);

protected:
	//! Internal function to create RegisteredSecret from S3AuthParams
	static shared_ptr<RegisteredSecret> CreateSecretFunctionInternal(ClientContext &context, CreateSecretInput& input, S3AuthParams params);

	//! Function for the "settings" provider: creates secret from current duckdb settings
	static shared_ptr<RegisteredSecret> CreateS3SecretFromSettings(ClientContext &context, CreateSecretInput& input);
	//! Function for the "config" provider: creates secret from parameters passed by user
	static shared_ptr<RegisteredSecret> CreateS3SecretFromConfig(ClientContext &context, CreateSecretInput& input);

	//! Helper function to set named params of secret function
	static void SetBaseNamedParams(CreateSecretFunction &function, string &type);
	//! Helper function to create secret types s3/r2/gcs
	static void RegisterCreateSecretFunction(DatabaseInstance &instance, string type);
};

} // namespace duckdb
