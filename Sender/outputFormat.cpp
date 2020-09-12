#include"outputFormat.h"

std::vector<std::string> DateFormat
= { "dd mm yyyy", "mm dd yyyy", "yyyy mm dd", "yyyy dd mm" };

std::vector<std::string> TimeFormat
= { "hh mm" };

OutputFormat::OutputFormat() :
	_date_format("dd mm yyyy"), _time_format("hh mm"), _total_format("dd mm yyyy hh mm") {}

OutputFormat::OutputFormat(std::string formatFromFile) :
	_date_format("dd mm yyyy"), _time_format("hh mm"), _total_format("dd mm yyyy hh mm")
{
	UpdateFormat(formatFromFile);
}

void OutputFormat::UpdateFormat(std::string formatFromFile)
{
	if (FormatIsValid(formatFromFile))
		_total_format = _date_format + SEPARATOR + _time_format;
}

bool OutputFormat::FormatIsValid(std::string formatFromFile)
{
	std::string date_copy, time_copy;

	if (formatFromFile.length() == TOTAL_FORMAT_LENGTH)
	{
		date_copy = formatFromFile.substr(0,DATE_FORMAT_LENGTH);
		time_copy = formatFromFile.substr(DATE_FORMAT_LENGTH + SEPARATOR_LENGTH, TIME_FORMAT_LENGTH);

		return (DateFormatIsValid(date_copy) && TimeFormatIsValid(time_copy));
	}
	return false;
}
bool OutputFormat::DateFormatIsValid(std::string date_copy)
{ 
	if (std::find(DateFormat.begin(), DateFormat.end(), date_copy) != DateFormat.end())
	{
		_date_format = date_copy;
		return true;
	}
	return false;
}
bool OutputFormat::TimeFormatIsValid(std::string time_copy)
{ 
	if (std::find(TimeFormat.begin(), TimeFormat.end(), time_copy) != TimeFormat.end())
	{
		_time_format = time_copy;
		return true;
	}
	return false;
}
std::string OutputFormat::Get_Format() { return _total_format; }
std::string OutputFormat::Get_DateFormat() { return _date_format; }
std::string OutputFormat::Get_TimeFormat() { return _time_format; }