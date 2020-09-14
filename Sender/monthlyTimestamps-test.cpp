//#define TEST_MONTHLY_TIMESTAMPS

#ifdef TEST_MONTHLY_TIMESTAMPS

#define CATCH_CONFIG_MAIN
#include"monthlyTimestamps.h"
#include"../catch.hpp"

TEST_CASE("monthly-timestamp")
{
	std::string fileName = "./test-data/input.csv";
	MonthlyTimestamps test(fileName);

	std::vector<int> footfalls
		= { 81,21,37,27,23,98,45,37,31,25,58,104,64,78,20,68,60,73,30,28,13,56,51,56,67,36,77,70,45,68,83 };
	
	for (unsigned int i = 0; i < footfalls.size(); i++)
	{
		REQUIRE((test.GetHoursOn(i)).size() == (unsigned int)footfalls[i]);
		REQUIRE((test.GetMinutesOn(i)).size() == (unsigned int)footfalls[i]);
	}
}



#endif