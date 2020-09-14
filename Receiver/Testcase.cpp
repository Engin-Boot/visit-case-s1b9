#ifdef Testcase

//#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include "Data.h"
#include "Receiver.h"


TEST_CASE("Data - Default Constructor + Get Member Variables")
{
	Data test1;
	REQUIRE(test.getDate() == 1);
	REQUIRE(test.getMonth() == 1);
	REQUIRE(test.getYear() == 2000);
	REQUIRE(test.getHour() == 0);
	REQUIRE(test.getMinute() == 0);
}

TEST_CASE("Data - Parameterized Constructor +  Get Member Variables")
{
	Data test2(14,9,2020,7,0);
	REQUIRE(test.getDate() == 14);
	REQUIRE(test.getMonth() == 9);
	REQUIRE(test.getYear() == 2020);
	REQUIRE(test.getHour() == 7);
	REQUIRE(test.getMinute() == 0);
}


TEST_CASE("Reciever - Default Constructor + Get Member Variables")
{
	Receiver test3;
	REQUIRE(test.getHours() == 24);
	REQUIRE(test.getDays() == 31);
	
}

TEST_CASE("Reciever - One Parameter which is the month value")
{
	Receiver test4(1);
	REQUIRE(test.getHours() == 24);
	REQUIRE(test.getDays() == 31);
}

TEST_CASE("when the checkMonth method is called to get the days in the respective month")
{
	Receiver test5;
	
	REQUIRE(test5.checkMonth(9) == 30);
	REQUIRE(test5.checkMonth(1) == 31);
	REQUIRE(test5.checkMonth(2) == 28);
	REQUIRE(test5.checkMonth(13) == 0);
	REQUIRE(test5.checkMonth(0) == 0);
}



#endif // Testcase
