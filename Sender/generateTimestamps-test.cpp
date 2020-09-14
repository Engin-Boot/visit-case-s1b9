//#define TEST_GENERATE_TIMESTAMPS

#ifdef TEST_GENERATE_TIMESTAMPS
#define CATCH_CONFIG_MAIN

#include"../catch.hpp"
#include"generateTimestamps.h"
#include<iostream>

TEST_CASE("Random number generator")
{
	srand(time(NULL));
	int random_seed_value = (rand() % 10);
	RandomGenerator gen(10, 1000, (unsigned long)random_seed_value);

	for (int i = 0; i < 31; i++)
	{
		int num = gen();
		REQUIRE(num >= 10);
		REQUIRE(num < 1000);

	}
}

TEST_CASE("Hours from timestamps")
{
	DayTimestamps test(20);
	std::vector<int> hours = test.GetDailyHours();
	REQUIRE(hours.size() == 20);

	int min = hours[0];

	for (unsigned int i = 0; i < 20; i++)
	{
		REQUIRE(hours[i] >= 0);
		REQUIRE(hours[i] < 24);
		REQUIRE(hours[i] >= min);

		min = hours[i];
	}

}

TEST_CASE("Minutes from timestamps")
{
	DayTimestamps test(20);
	std::vector<int> minutes = test.GetDailyMinutes();
	REQUIRE(minutes.size() == 20);
	for (unsigned int i = 0; i < 20; i++)
	{
		REQUIRE(minutes[i] >= 0);
		REQUIRE(minutes[i] < 60);
	}
}

#endif