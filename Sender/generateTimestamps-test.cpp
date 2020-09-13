#define TEST_GENERATE_TIMESTAMPS

#ifdef TEST_GENERATE_TIMESTAMPS
#define CATCH_CONFIG_MAIN

#include"../catch.hpp"
#include"generateTimestamps.h"

TEST_CASE("GenerateRandomNumbers-size")
{
	unsigned int size = 10;
	REQUIRE(generateRandomNumbers(size).size() == size);
}

TEST_CASE("GenerateRandomNumbers-range")
{
	int size = 5;
	std::vector<int> numbers = generateRandomNumbers(size);
	REQUIRE(((numbers[0] >= 0) && (numbers[0] <= 1440))==true);
	REQUIRE(((numbers[1] >= 0) && (numbers[1] <= 1440))==true);
	REQUIRE(((numbers[2] >= 0) && (numbers[2] <= 1440))==true);
	REQUIRE(((numbers[3] >= 0) && (numbers[3] <= 1440))==true);
	REQUIRE(((numbers[4] >= 0) && (numbers[4] <= 1440))==true);
}

TEST_CASE("GenerateRandomNumbers-sorted")
{
	int size = 5;
	std::vector<int> numbers = generateRandomNumbers(size);
	REQUIRE((numbers[4]>=numbers[3])==true);
	REQUIRE((numbers[3] >= numbers[2])==true);
	REQUIRE((numbers[2] >= numbers[1])==true);
	REQUIRE((numbers[1] >= numbers[0])==true);
}

TEST_CASE("Hours and minutes from timestamps")
{
	std::vector<int> numbers = { 0, 65, 157, 199, 250, 348, 362, 433, 491, 540, 659, 689 };
	std::vector<int> hours = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	std::vector<int> minutes = { 0, 5, 37, 19, 10, 48, 2, 13, 11, 0, 59, 29 };

	DayTimestamps test(numbers);

	REQUIRE(test.GetDailyHours() == hours);
	REQUIRE(test.GetDailyMinutes() == minutes);
}

#endif