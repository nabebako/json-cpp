#include <fstream>
#include <regex>
#include <vector>
#include <memory>
#include <iostream>

#include "config.hpp"
#include "json-parser/json.hpp"

namespace CppConfig
{
	std::shared_ptr<JSON::Object> parseConfigFile()
	{
		auto object = std::make_shared<JSON::Object>();
		std::ifstream configFile("cppconfig.json");

		// const auto complierConfig = new CppConfig::ComplierConfig();

		if (configFile)
		{
			configFile.seekg(0, configFile.end);
    		int length = configFile.tellg();
    		configFile.seekg(0, configFile.beg);

			auto *buffer = new char [length];

    		configFile.read(buffer, length);
	    	configFile.close();

			object = JSON::parse(std::string(buffer));
			
			delete[] buffer;
		}
		return object;
	}
}