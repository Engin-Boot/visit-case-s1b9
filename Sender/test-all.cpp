#include"test-all.h"

#ifdef TEST_ALL

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include "monthlyData.h"
#include "fileReader.h"
#include"outputFormat.h"
#include"data_from_csv.h"
#include"generateTimestamps.h"

#include"outputPrinter.h"
#include"monthlyTimestamps.h"
#include<sstream>

#ifdef TEST_MONTHLY_DATA

TEST_CASE("IsLeapYear-Tests")
{
	REQUIRE(IsLeapYear(2015) == false);
	REQUIRE(IsLeapYear(1970) == false);
	REQUIRE(IsLeapYear(1996) == true);
	REQUIRE(IsLeapYear(2100) == false);
	REQUIRE(IsLeapYear(2000) == true);
	REQUIRE(IsLeapYear(1800) == false);
}

TEST_CASE("MonthlyData - Default Constructor + Get Member Variables")
{
	MonthlyData test;
	REQUIRE(test.GetMonth() == 1);
	REQUIRE(test.GetYear() == 2000);
	REQUIRE(test.GetNoOfDays() == 31);
}

TEST_CASE("MonthlyData - Two Arg Constructor")
{
	MonthlyData test1;
	test1.UpdateValues(4, 2020);
	REQUIRE(test1.GetMonth() == 4);
	REQUIRE(test1.GetYear() == 2020);
	REQUIRE(test1.GetNoOfDays() == 30);
}

TEST_CASE("MonthIsValid, YearIsValid")
{
	MonthlyData test1;
	test1.UpdateValues(0, 0);
	REQUIRE(test1.GetMonth() == 1);
	REQUIRE(test1.GetYear() == 2000);
	REQUIRE(test1.GetNoOfDays() == 31);

	MonthlyData test2;
	test1.UpdateValues(23, 1000);
	REQUIRE(test2.GetMonth() == 1);
	REQUIRE(test2.GetYear() == 2000);
	REQUIRE(test2.GetNoOfDays() == 31);
}

TEST_CASE("Update_no_of_days")
{
	MonthlyData test1;
	test1.UpdateValues(2, 2012);
	REQUIRE(test1.GetMonth() == 2);
	REQUIRE(test1.GetYear() == 2012);
	REQUIRE(test1.GetNoOfDays() == 29);

	MonthlyData test2;
	test2.UpdateValues(2, 2011);
	REQUIRE(test2.GetMonth() == 2);
	REQUIRE(test2.GetYear() == 2011);
	REQUIRE(test2.GetNoOfDays() == 28);
}

TEST_CASE("Get footfall values")
{
	std::vector<int> footfall_test = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30 };
	MonthlyData test1;
	test1.UpdateValues(4, 2020);
	test1.UpdateFootfallPerDay(footfall_test);

	REQUIRE(test1.GetFootfallPerDay() == footfall_test);
}

#endif

#ifdef TEST_FILE_READER

TEST_CASE("ReadFile - default - with safe file")
{
	FileReader reader1("random");
	std::vector<std::string> lines1 = reader1.GetFileLines();
	
	REQUIRE(reader1.ReadIsGood == true);

	REQUIRE(lines1[0].compare("This,is,a,safe,file") == 0);
	REQUIRE(lines1[1].compare("It,has,two,lines") == 0);
	REQUIRE(lines1.size() == 2);

}

//TEST_CASE("ReadFile - default - without safe file")
//{
//	FileReader reader1("random");
//	std::vector<std::string> lines1 = reader1.GetFileLines();
//
//	REQUIRE(reader1.ReadIsGood == false);
//
//	REQUIRE(lines1.size() == 33);
//	REQUIRE(lines1[0].compare("Safe,file,not,present") == 0);
//	REQUIRE(lines1[1].compare("default,values,loaded") == 0);
//	REQUIRE(lines1[2].compare("1,1") == 0);
//	REQUIRE(lines1[32].compare("31,1") == 0);
//}


TEST_CASE("ReadFile - actual input")
{
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

#ifdef TEST_OUTPUT_FORMAT

TEST_CASE("OutputFormat - default values")
{
	OutputFormat test;
	test.UpdateFormat("this is incorrect");
	REQUIRE((test.Get_DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE((test.Get_Format()).compare("dd mm yyyy hh mn") == 0);

	OutputFormat test2;
	test2.UpdateFormat("aa bb cccc dd ee");
	REQUIRE((test2.Get_DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE((test2.Get_Format()).compare("dd mm yyyy hh mn") == 0);

	OutputFormat test3;
	test3.UpdateFormat("aa bb cccc hh mn");
	REQUIRE((test3.Get_DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE((test3.Get_Format()).compare("dd mm yyyy hh mn") == 0);
}

TEST_CASE("OutputFormat - given correct values")
{
	OutputFormat test;
	test.UpdateFormat("mm dd yyyy hh mn");
	REQUIRE((test.Get_DateFormat()).compare("mm dd yyyy") == 0);
	REQUIRE((test.Get_Format()).compare("mm dd yyyy hh mn") == 0);
}

#endif

#ifdef TEST_GET_FOOTFALLS_FROM_CSV

TEST_CASE("Split String function")
{
	std::string data = "1,81,38";
	std::vector<int> split_data = SplitString(data);
	REQUIRE(split_data[0] == 1);
	REQUIRE(split_data[1] == 81);
	REQUIRE(split_data[2] == 38);
}

TEST_CASE("DataFrom_csv - correct input")
{
	std::string fileName = "./test-data/input.csv";
	DataFrom_csv aug_data(fileName);
	std::vector<int> footfalls
		= { 81,21,37,27,23,98,45,37,31,25,58,104,64,78,20,68,60,73,30,28,13,56,51,56,67,36,77,70,45,68,83 };

	REQUIRE((aug_data.GetOutputFormat()).compare("dd mm yyyy hh mn") == 0);
	REQUIRE((aug_data.DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE(aug_data.GetMonth() == 8);
	REQUIRE(aug_data.GetYear() == 2020);
	REQUIRE(aug_data.GetFootfallValues() == footfalls);
}

TEST_CASE("DataFrom_csv - default")
{
	std::string fileName = "random";
	DataFrom_csv aug_data(fileName);
	std::vector<int> footfalls(31);
	std::fill(footfalls.begin(), footfalls.end(), 1);
	
	REQUIRE((aug_data.GetOutputFormat()).compare("dd mm yyyy hh mn") == 0);
	REQUIRE((aug_data.DateFormat()).compare("dd mm yyyy") == 0);
	REQUIRE(aug_data.GetMonth() == 1);
	REQUIRE(aug_data.GetYear() == 2000);
	REQUIRE(aug_data.GetFootfallValues() == footfalls);
}

#endif

#ifdef TEST_GENERATE_TIMESTAMPS

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

#ifdef TEST_PRINT_OUTPUT

TEST_CASE("print date 1")
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());

	std::string date_format = "mm dd yyyy";
	Output_DatePrinter test(4, 2020, date_format);

	test.Print_Date(13);

	std::cout.rdbuf(p_cout_streambuf);
	REQUIRE(oss);
	REQUIRE(oss.str() == "04 13 2020");

}

TEST_CASE("print date 2")
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());

	std::string date_format = "yyyy dd mm";
	Output_DatePrinter test(4, 2020, date_format);

	test.Print_Date(24);

	std::cout.rdbuf(p_cout_streambuf);
	REQUIRE(oss);
	REQUIRE(oss.str() == "2020 24 04");
}

TEST_CASE("print time")
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());

	PrintTime(14, 1);

	std::cout.rdbuf(p_cout_streambuf);
	REQUIRE(oss);
	REQUIRE(oss.str() == "14 01");
}

TEST_CASE("print FirstLine")
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());

	std::string format = "yyyy dd mm";
	Output_DatePrinter tester(4, 2020, format);

	tester.Print_FirstLine();

	std::cout.rdbuf(p_cout_streambuf);
	REQUIRE(oss);
	REQUIRE(oss.str() == "04 2020\n");
}

TEST_CASE("print format")
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());

	std::string format = "this is format";
	PrintFormatLine(format);

	std::cout.rdbuf(p_cout_streambuf);
	REQUIRE(oss);
	REQUIRE(oss.str() == "this is format\n");
}


#endif

#ifdef TEST_MONTHLY_TIMESTAMPS

//TEST_CASE("monthly-timestamp")
//{
//	std::string fileName = "./test-data/input.csv";
//	MonthlyTimestamps test(fileName);
//
//	std::vector<int> footfalls
//		= { 81,21,37,27,23,98,45,37,31,25,58,104,64,78,20,68,60,73,30,28,13,56,51,56,67,36,77,70,45,68,83 };
//
//	for (unsigned int i = 0; i < footfalls.size(); i++)
//	{
//		REQUIRE((test.GetHoursOn(i)).size() == (unsigned int)footfalls[i]);
//		REQUIRE((test.GetMinutesOn(i)).size() == (unsigned int)footfalls[i]);
//	}
//}

TEST_CASE("print output")
{
	std::ostringstream oss;
	std::streambuf* p_cout_streambuf = std::cout.rdbuf();
	std::cout.rdbuf(oss.rdbuf());

	std::string fileName = "./test-data/input.csv";
	MonthlyTimestamps aug(fileName);
	aug.PrintOutput();

	std::cout.rdbuf(p_cout_streambuf);
	REQUIRE(oss);
	REQUIRE((oss.str()).empty()==false);
}

#endif

#endif