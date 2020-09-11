#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "fileReader.h"

TEST_CASE("TwoArg Constructor")
{	FileReader reader1("random");
	REQUIRE((reader1.GetFileName()).compare("SafeFile.csv") == 0);

	FileReader reader2("./test-data/input.csv");
	REQUIRE((reader2.GetFileName()).compare("./test-data/input.csv") == 0);
}