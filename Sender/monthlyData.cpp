#include"monthlyData.h"

std::vector<int> DaysInTheMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };

bool IsLeapYear(int year)
{ return((!(year % 4) && (year % 100)) || !(year % 400)); }

MonthlyData::MonthlyData() :_month(1), _year(2000), _no_of_days(31) {}

MonthlyData::MonthlyData(int month, int year): _month(1), _year(2000), _no_of_days(31)
{
	UpdateValues(month, year);
}

void MonthlyData::UpdateValues(int month, int year)
{
	if (MonthIsValid(month))
		_month = month;
	if (YearIsValid(year))
		_year = year;
	Update_no_of_days();
}

bool MonthlyData::MonthIsValid(int month)
{ return((month > 0) && (month < 13)); }

bool MonthlyData::YearIsValid(int year)
{ return((year > 1500) && (year < 2500)); }

void MonthlyData::Update_no_of_days()
{
	_no_of_days = DaysInTheMonth[_month - 1];
	
	if(_month==2)
		if(IsLeapYear(_year))
			_no_of_days++;
}

void MonthlyData::UpdateFootfallPerDay(std::vector<int> footfall_per_day)
{
	if (footfall_per_day.size() == _no_of_days)
		_footfall_per_day = footfall_per_day;
}
int  MonthlyData::GetMonth() { return _month; }
int  MonthlyData::GetYear() { return _year; }
int MonthlyData::GetNoOfDays() { return _no_of_days; }
std::vector<int>  MonthlyData::GetFootfallPerDay() { return _footfall_per_day; }
