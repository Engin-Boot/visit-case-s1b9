#define TEST_PRINT_OUTPUT

#ifdef TEST_PRINT_OUTPUT

#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"outputPrinter.h"

TEST_CASE("split-string 1")
{
	std::string date_format = "yyyy dd mm";
	Output_DatePrinter test(4, 2020, date_format);

	REQUIRE((test.FirstField()).compare("yyyy") == 0);
	REQUIRE((test.SecondField()).compare("dd") == 0);
	REQUIRE((test.ThirdField()).compare("mm") == 0);
}

TEST_CASE("split-string 2")
{
	std::string date_format = "yyyy mm dd";
	Output_DatePrinter test(4, 2020, date_format);

	REQUIRE((test.FirstField()).compare("yyyy") == 0);
	REQUIRE((test.SecondField()).compare("mm") == 0);
	REQUIRE((test.ThirdField()).compare("dd") == 0);
}

TEST_CASE("split-string 3")
{
	std::string date_format = "dd mm yyyy";
	Output_DatePrinter test(4, 2020, date_format);

	REQUIRE((test.FirstField()).compare("dd") == 0);
	REQUIRE((test.SecondField()).compare("mm") == 0);
	REQUIRE((test.ThirdField()).compare("yyyy") == 0);
}

TEST_CASE("split-string 4")
{
	std::string date_format = "mm dd yyyy";
	Output_DatePrinter test(4, 2020, date_format);

	REQUIRE((test.FirstField()).compare("mm") == 0);
	REQUIRE((test.SecondField()).compare("dd") == 0);
	REQUIRE((test.ThirdField()).compare("yyyy") == 0);
}



#endif