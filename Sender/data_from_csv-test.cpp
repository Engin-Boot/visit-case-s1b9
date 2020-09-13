//#define TEST_GET_FOOTFALLS_FROM_CSV

#ifdef TEST_GET_FOOTFALLS_FROM_CSV

#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"data_from_csv.h"

TEST_CASE("Split String function")
{
	std::string data = "1,81,38";
	std::vector<int> split_data = SplitString(data);
	REQUIRE(split_data[0] == 1);
	REQUIRE(split_data[1] == 81);
	REQUIRE(split_data[2] == 38);
}

TEST_CASE("DataFrom_csv")
{
	std::string fileName = "./test-data/input.csv";
	DataFrom_csv aug_data(fileName);
	std::vector<int> footfalls
	= { 81,21,37,27,23,98,45,37,31,25,58,104,64,78,20,68,60,73,30,28,13,56,51,56,67,36,77,70,45,68,83 };

	REQUIRE((aug_data.GetOutputFormat()).compare("dd mm yyyy hh mm") == 0);
	REQUIRE(aug_data.GetMonth() == 8);
	REQUIRE(aug_data.GetYear() == 2020);
	REQUIRE(aug_data.GetFootfallValues() == footfalls);
}




#endif