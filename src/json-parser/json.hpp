#pragma once

#include <string>
#include <map>
#include <variant>
#include <memory>
#include <vector>

namespace JSON
{
	typedef std::variant<std::string, float, bool> Data;
	typedef std::map<std::string, Data> Object;

	std::shared_ptr<Object> parse(const std::string &JSON);
	Data parseValue(const std::string &JSON);
	void print(const Object &object);
	std::vector<std::string> keys(const Object &object);
}