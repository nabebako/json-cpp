#pragma once

#include <memory>
#include "json-parser/json.hpp"

#define jsonRegex "\"[a-z]+\"\\s*:\\s*\"?[a-z]+\"?(?=\\,?)"

namespace CppConfig
{
	enum class targetOptions {
		ES2015, ES2016, ES2017, ES2018, ES2019, ES2020, ES2021, ESNext
	};

	struct ComplierConfig
	{
		targetOptions target = targetOptions::ES2017;
		bool esModuleInterop = true;
		bool forceConsistentCasingInFileNames = true;
		bool strict = true;
		bool skipLibCheck = true;
	};

	std::shared_ptr<JSON::Object> parseConfigFile();
}