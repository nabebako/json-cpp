#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <regex>

#include "config/config.hpp"
#include "json-parser/json.hpp"

#define LOG(x) std::cout << x << "\n";

using string = std::string;
using flagPair = std::pair<const string, const string>;
using flagHashMap = std::map<const string, const string>;

flagHashMap findFlags(std::vector<string> &args)
{
	flagHashMap flags;
	for (auto &arg : args) if (std::regex_match(arg, std::regex("--.*|-[a-zA-Z]"))) flags.insert(flagPair(arg, ""));
	return flags;
}

int main(int argc, char const *argv[])
{
	auto res = CppConfig::parseConfigFile();
	JSON::print(*res);

	// std::vector<string> args;
	// for (size_t i = 1; i < argc; i++) args.push_back(argv[i]);

	// flagHashMap flags = findFlags(args);
	// for (auto &flag : flags) LOG(flag.first);

	// CppConfig::getConfigFile();
	
	return 0;
}