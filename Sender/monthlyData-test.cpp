
#define CATCH_CONFIG_MAIN

#include "../catch.hpp"
#include "monthlyData.h"
/*
TEST_CASE("IsLeapYear-Tests")
{	REQUIRE(IsLeapYear(2015) == false); 
	REQUIRE(IsLeapYear(1970) == false);
	REQUIRE(IsLeapYear(1996) == true);
	REQUIRE(IsLeapYear(2100) == false);
	REQUIRE(IsLeapYear(2000) == true);
	REQUIRE(IsLeapYear(1800) == false);
}

TEST_CASE("MonthlyData - Default Constructor + Get Member Variables")
{	MonthlyData test;
	REQUIRE(test.GetMonth() == 1);
	REQUIRE(test.GetYear() == 2000);
	REQUIRE(test.GetNoOfDays() == 31);
}

TEST_CASE("MonthlyData - Two Arg Constructor")
{	MonthlyData test1(4,2020);
	REQUIRE(test1.GetMonth() == 4);
	REQUIRE(test1.GetYear() == 2020);
	REQUIRE(test1.GetNoOfDays() == 30);
}

TEST_CASE("MonthIsValid, YearIsValid")
{	MonthlyData test1(0, 0);
	REQUIRE(test1.GetMonth() == 1);
	REQUIRE(test1.GetYear() == 2000);
	REQUIRE(test1.GetNoOfDays() == 31);

	MonthlyData test2(23, 1000);
	REQUIRE(test2.GetMonth() == 1);
	REQUIRE(test2.GetYear() == 2000);
	REQUIRE(test2.GetNoOfDays() == 31);
}

TEST_CASE("Update_no_of_days")
{	MonthlyData test1(2, 2012);
	REQUIRE(test1.GetMonth() == 2);
	REQUIRE(test1.GetYear() == 2012);
	REQUIRE(test1.GetNoOfDays() == 29);

	MonthlyData test2(2, 2011);
	REQUIRE(test2.GetMonth() == 2);
	REQUIRE(test2.GetYear() == 2011);
	REQUIRE(test2.GetNoOfDays() == 28);
}
*/