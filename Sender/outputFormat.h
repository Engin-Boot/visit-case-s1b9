#pragma once
#include"test-all.h"
#include<string>
#include<vector>
#include<algorithm>

#define DATE_FORMAT_LENGTH 10
#define TIME_FORMAT_LENGTH 5
#define SEPARATOR_LENGTH 1
#define TOTAL_FORMAT_LENGTH 16
#define SEPARATOR " "

extern std::vector<std::string> DateFormat;
extern std::vector<std::string> TimeFormat;

class OutputFormat
{
private:
	std::string _date_format;
	std::string _time_format;

	std::string _total_format;

	bool FormatIsValid(std::string);
	bool DateFormatIsValid(std::string);
	bool TimeFormatIsValid(std::string);

public:
	OutputFormat();
	void UpdateFormat(const char *);
	std::string Get_Format();
	std::string Get_DateFormat();

};