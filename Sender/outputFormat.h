#pragma once
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
	explicit OutputFormat(std::string);
	std::string Get_Format();
	std::string Get_DateFormat();
	std::string Get_TimeFormat();
};