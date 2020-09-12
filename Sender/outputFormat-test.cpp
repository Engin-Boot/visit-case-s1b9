#define TEST_OUTPUT_FORMAT

#ifdef TEST_OUTPUT_FORMAT

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include"outputFormat.h"

TEST_CASE("OutputFormat - default values")
{
	OutputFormat test("this is incorrect");
	REQUIRE((test.Get_DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE((test.Get_TimeFormat()).compare("hh mm") == 0);
	REQUIRE((test.Get_Format()).compare("dd mm yyyy hh mm") == 0);

	OutputFormat test2("aa bb cccc dd ee");
	REQUIRE((test2.Get_DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE((test2.Get_TimeFormat()).compare("hh mm") == 0);
	REQUIRE((test2.Get_Format()).compare("dd mm yyyy hh mm") == 0);

	OutputFormat test3("aa bb cccc hh mm");
	REQUIRE((test3.Get_DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE((test3.Get_TimeFormat()).compare("hh mm") == 0);
	REQUIRE((test3.Get_Format()).compare("dd mm yyyy hh mm") == 0);
}

TEST_CASE("OutputFormat - given correct values")
{
	OutputFormat test("mm dd yyyy hh mm");
	REQUIRE((test.Get_DateFormat()).compare("mm dd yyyy") == 0);
	REQUIRE((test.Get_TimeFormat()).compare("hh mm") == 0);
	REQUIRE((test.Get_Format()).compare("mm dd yyyy hh mm") == 0);
}

#endif