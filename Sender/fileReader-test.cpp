//#define TEST_FILE_READER

#ifdef TEST_FILE_READER

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include "fileReader.h"

TEST_CASE("TwoArg Constructor")
{	FileReader reader1("random");
	REQUIRE((reader1.GetFileName()).compare("./Sender/SafeFile.csv") == 0);

	FileReader reader2("./test-data/input.csv");
	REQUIRE((reader2.GetFileName()).compare("./test-data/input.csv") == 0);
}
TEST_CASE("ReturnFile is Good")
{
	FileReader reader1("random");
	REQUIRE(reader1.ReadIsGood == true);

	FileReader reader2("./test-data/input.csv");
	REQUIRE(reader2.ReadIsGood == true);
}

TEST_CASE("ReadFile")
{
	FileReader reader1("random");
	std::vector<std::string> lines1 = reader1.GetFileLines();
	REQUIRE(lines1[0].compare("This,is,a,safe,file") == 0);
	REQUIRE(lines1[1].compare("It,has,two,lines") == 0);
	REQUIRE(lines1.size() == 2);

	FileReader reader2("./test-data/input.csv");
	std::vector<std::string> lines2 = reader2.GetFileLines();

	REQUIRE(lines2[0].compare("dd mm yyyy,hh mn") == 0);
	REQUIRE(lines2[1].compare("08,2020") == 0);
	REQUIRE(lines2[2].compare("Date,Count") == 0);
	REQUIRE(lines2[3].compare("1,81") == 0);
	REQUIRE(lines2[33].compare("31,83") == 0);
	REQUIRE(lines2.size() == 34);
}

#endif