#pragma once
#include"test-all.h"
#include"data_from_csv.h"
#include"generateTimestamps.h"
#include"outputPrinter.h"

class MonthlyTimestamps
{
private:
	DataFrom_csv _data;
	std::vector<DayTimestamps> _timestamps;

	void UpdateDayTimestamps();
	
public:
	explicit MonthlyTimestamps(std::string& fileName);
	void PrintOutput();

#ifdef TEST_MONTHLY_TIMESTAMPS
	std::vector<int> GetHoursOn(int);
	std::vector<int> GetMinutesOn(int);
#endif

};