#pragma once
#include"test-all.h"
#include<vector>

extern std::vector<int> DaysInTheMonth;

bool IsLeapYear(int year);

class MonthlyData	//Possible issues: Can be overwritten. Footfall values may be invalid.
{
private:
	int _month;
	int _year;
	int _no_of_days;
	std::vector <int> _footfall_per_day;

	bool MonthIsValid(int month);
	bool YearIsValid(int year);
	void Update_no_of_days();

public:

	MonthlyData();
	void UpdateValues(int month, int year);
	void UpdateFootfallPerDay(std::vector<int> counts);
	int GetMonth();
	int GetYear();
	int GetNoOfDays();
	std::vector<int> GetFootfallPerDay();

};
