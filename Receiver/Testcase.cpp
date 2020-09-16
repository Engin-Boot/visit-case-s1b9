#include "Data.h"
#ifdef RECEIVER_TEST
#define CATCH_CONFIG_MAIN
#include"../catch.hpp"
#include"receiver.h"

using namespace std;


TEST_CASE("When a Default Data Constructor is called then assign member variables default values")
{
	Data test;

	REQUIRE(test.getDate() == 1);
	REQUIRE(test.getMonth() == 1);
	REQUIRE(test.getYear() == 2000);
	REQUIRE(test.getHour() == 0);
	REQUIRE(test.getMinute() == 0);
}

TEST_CASE("When a Parameterized Data Constructor is called then assign member variables with input values")
{
	Data test(14, 9, 2020, 7, 0);
	REQUIRE(test.getDate() == 14);
	REQUIRE(test.getMonth() == 9);
	REQUIRE(test.getYear() == 2020);
	REQUIRE(test.getHour() == 7);
	REQUIRE(test.getMinute() == 0);
}


TEST_CASE("When a Default Receiver Constructor is called then assign member variables default value")
{
	Receiver test;
	REQUIRE(test.getHours() == 24);
	REQUIRE(test.getDays() == 31);
}

TEST_CASE("When a Parameterized Receiver Constructor is called then assign member variables with input values")
{
	Receiver test(24, 31);
	REQUIRE(test.getHours() == 24);
	REQUIRE(test.getDays() == 31);
}

TEST_CASE("when the checkMonth method is called then return number of days in the respective month")
{
	REQUIRE(checkMonth(9) == 30);
	REQUIRE(checkMonth(1) == 31);
	REQUIRE(checkMonth(2) == 28);
	REQUIRE(checkMonth(13) == 0);
	REQUIRE(checkMonth(0) == 0);
}

TEST_CASE("When store in buffer method called then Store values in Buffer")
{
	Receiver testbuffer(24, 30);
	string data_format = "dd mm yyyy hh mn";
	string data_value = "15 09 2020 14 30";

	testbuffer.storeInBuffer(data_format, data_value);
	vector<Data> BufferFootfall = testbuffer.getBuffer();
	REQUIRE(BufferFootfall[0].getDate() == 15);
	REQUIRE(BufferFootfall[0].getMonth() == 9);
	REQUIRE(BufferFootfall[0].getYear() == 2020);
	REQUIRE(BufferFootfall[0].getHour() == 14);
	REQUIRE(BufferFootfall[0].getMinute() == 30);
}


TEST_CASE("When the buffer count goes above 4 Store the Buffer values in vector")
{
	Receiver test(24, 30);
	string data_format = "dd mm yyyy hh mn";
	string data_value1 = "15 09 2020 14 01";
	string data_value2 = "15 09 2020 14 10";
	string data_value3 = "15 09 2020 14 25";
	string data_value4 = "15 09 2020 15 30";
	string data_value5 = "15 09 2020 16 45";

	test.storeInBuffer(data_format, data_value1);
	test.storeInBuffer(data_format, data_value2);
	test.storeInBuffer(data_format, data_value3);
	test.storeInBuffer(data_format, data_value4);
	test.storeInBuffer(data_format, data_value5);

	vector<std::vector<int>> visitCount = test.getVisitCount();
	//visitCount : Row-hours column- Date-1.
	REQUIRE(visitCount[0][0] == 0);
	REQUIRE(visitCount[14][14] == 3);
	REQUIRE(visitCount[15][14] == 1);
	REQUIRE(visitCount[16][14] == 1);
	REQUIRE(visitCount[24][14] == 5);
}

TEST_CASE("Average Hourly count for specific number of hours and days")
{
	Receiver test;
	//setVisitCount(hour,date,count)
	test.setVisitCount(0, 0, 10);
	test.setVisitCount(0, 1, 10);
	test.setVisitCount(0, 2, 10);
	test.setVisitCount(0, 3, 10);
	test.setVisitCount(1, 0, 20);
	test.setVisitCount(1, 1, 10);
	test.setVisitCount(1, 2, 10);
	test.setVisitCount(2, 0, 10);
	test.setVisitCount(2, 1, 10);
	test.setVisitCount(3, 3, 45);

	//test.getAvgHourlyfootfall(noofHours,noofDays);
	test.getAvgHourlyfootfall(4, 4);
	vector<float> hourlyAvgFootfall = test.gethourAvg();
	REQUIRE(hourlyAvgFootfall[0] == 10.0f);
	REQUIRE(hourlyAvgFootfall[1] == 10.0f);
	REQUIRE(hourlyAvgFootfall[2] == 5.0f);
	REQUIRE(hourlyAvgFootfall[3] == 11.25f);
}

TEST_CASE("Average Daily Footfall for a month")
{
	Receiver test;
	test.setVisitCount(24, 0, 40);
	test.setVisitCount(24, 1, 60);
	test.setVisitCount(24, 2, 30);
	test.setVisitCount(24, 3, 70);
	test.setVisitCount(24, 4, 20);
	test.setVisitCount(24, 5, 80);
	test.setVisitCount(24, 6, 70);
	test.setVisitCount(24, 7, 40);

	test.getAvgDailyfootfall();
	vector<float> DailyAvgFootfall = test.getDailyAvg();
	REQUIRE(DailyAvgFootfall[0] == 16.0f);
	REQUIRE(DailyAvgFootfall[1] == 12.0f);
	REQUIRE(DailyAvgFootfall[2] == 6.0f);
	REQUIRE(DailyAvgFootfall[3] == 17.5f);
	REQUIRE(DailyAvgFootfall[4] == 5.0f);
	REQUIRE(DailyAvgFootfall[5] == 20.0f);
	REQUIRE(DailyAvgFootfall[6] == 17.5f);
}

TEST_CASE("Peak Footfall Count for a month")
{
	Receiver test;
	//setVisitCount(Hour,date-1, value);
	test.setVisitCount(24, 0, 40);
	test.setVisitCount(24, 1, 60);
	test.setVisitCount(24, 2, 30);
	test.setVisitCount(24, 3, 70);
	test.setVisitCount(24, 4, 20);
	test.setVisitCount(24, 5, 80);
	test.setVisitCount(24, 6, 70);
	test.setVisitCount(24, 7, 40);

	int peak = test.getPeekDailyfootfallMontly();
	int date = test.getPeakDateValue();
	REQUIRE(peak == 80);
	REQUIRE(date == 6);
}

TEST_CASE("When Clear Buffer method called check whether Buffer is Empty or not")
{
	Receiver test;
	test.clearBuffer();
	vector<Data> BufferFootfall = test.getBuffer();
	REQUIRE(BufferFootfall.empty() == true);
}

TEST_CASE("Store in CSV File")
{
	Receiver test;
	//setVisitCount(hour,date-1,count);
	test.setVisitCount(0, 0, 10);
	test.setVisitCount(0, 1, 10);
	test.setVisitCount(0, 2, 10);
	test.setVisitCount(0, 3, 10);
	test.setVisitCount(1, 0, 20);
	test.setVisitCount(1, 1, 10);
	test.setVisitCount(1, 2, 10);
	test.setVisitCount(2, 0, 10);
	test.setVisitCount(2, 1, 10);
	test.setVisitCount(3, 3, 45);
	test.setVisitCount(0, 4, 20);
	test.setVisitCount(5, 5, 80);
	test.setVisitCount(4, 6, 70);
	test.setVisitCount(3, 7, 40);
	test.setVisitCount(24, 0, 40);
	test.setVisitCount(24, 1, 30);
	test.setVisitCount(24, 2, 20);
	test.setVisitCount(24, 3, 55);
	test.setVisitCount(24, 4, 20);
	test.setVisitCount(24, 5, 80);
	test.setVisitCount(24, 6, 70);
	test.setVisitCount(24, 7, 40);

	test.getAvgHourlyfootfall(4, 4);
	test.getAvgDailyfootfall();
	test.getPeekDailyfootfallMontly();

	test.StoreInCSV();
	ifstream fin1("Receiver.csv");
	string line1, line2, line3, line4;
	getline(fin1, line1);
	REQUIRE(line1 == "Hour,Average");
	int i = 5;
	while (i--)
	{
		getline(fin1, line1);
	}
	getline(fin1, line2);
	REQUIRE(line2 == "Day,Average");
	i = 8;
	while (i--)
	{
		getline(fin1, line2);
	}
	getline(fin1, line3);
	REQUIRE(line3 == "Month,Value");
	getline(fin1, line4);
	REQUIRE(line4 == "6,80");
	fin1.close();
}

TEST_CASE("Test the function split used")
{
	string stringFormat = "dd mm yyyy hh mn";
	vector<string> vectorStringFormat;
	split(vectorStringFormat, stringFormat, ' ');
	REQUIRE(vectorStringFormat[0] == "dd");
	REQUIRE(vectorStringFormat[1] == "mm");
	REQUIRE(vectorStringFormat[2] == "yyyy");
	REQUIRE(vectorStringFormat[3] == "hh");
	REQUIRE(vectorStringFormat[4] == "mn");
}

TEST_CASE("Check get Month and Year Function")
{
	string month_year = "08 2020";
	vector<int> result=getMonthandYear(month_year);
	REQUIRE(result[0] == 8);
	REQUIRE(result[1] == 2020);
}


#endif // Testcase
