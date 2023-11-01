#include "json-parser/json.hpp"

int main()
{
	JSON::print(*JSON::parse("{test: 1}"));
	return 0;
}