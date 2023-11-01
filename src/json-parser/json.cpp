#include <string>
#include <regex>
#include <stdexcept>
#include <iostream>

#include "json.hpp"

#define i std::regex::icase
#define opt std::regex::optimize

namespace JSON
{
	Data parseValue(const std::string &value)
	{
		std::smatch m;
		if (std::regex_match(value, m, std::regex("[\"\\']([a-z0-9]+)[\"\\']", i|opt))) { return m[1].str(); }
		if (std::regex_match(value, m, std::regex("[0-9]+\\.?[0-9]*", opt))) { return std::stof(m.str()); }
		if (std::regex_match(value, m, std::regex("true", opt))) { return true; }
		if (std::regex_match(value, m, std::regex("false", opt))) { return false; }
		throw std::invalid_argument(std::string("parse failed, value: ") + value);
		return std::string("");
	}

	std::shared_ptr<Object> parse(const std::string &JSON)
	{
		auto jsObj = std::make_shared<Object>();

		// if (std::regex_match(JSON, std::regex("[\\{\\[].*[\\}\\]]")))
		{
			std::smatch extractedPair;
			auto searchStart = JSON.cbegin();

			while (std::regex_search(searchStart, JSON.cend(), extractedPair, std::regex("[\"']?([\\w\\d]+)[\"']?\\s*:\\s*(\"?[\\w\\d\\.]+\"?)", i|opt)))
			{
				(*jsObj)[extractedPair[1].str()] = parseValue(extractedPair[2].str());
        		searchStart = extractedPair.suffix().first;
			}
		}

		return jsObj;
	}

	void print(const Object &object)
	{
		std::cout << "{\n";
		for (auto &[key, data] : object)
		{
			std::cout << "   " << key << ": ";

			if (auto value = std::get_if<std::string>(&data)) std::cout << "\"" << *value << "\",\n";
			if (auto value = std::get_if<float>(&data)) std::cout << *value << ",\n";
			if (auto value = std::get_if<bool>(&data)) 
			{
				if (*value) std::cout << "true,\n";
				else std::cout << "false,\n";
			}			
		}
		std::cout << "}" << std::endl;
	}

	std::vector<std::string> keys(const Object &object)
	{
		auto result = std::vector<std::string>();
		result.reserve(object.size());

		for (auto &pair : object) result.push_back(pair.first);
		
		return result;
	}
}