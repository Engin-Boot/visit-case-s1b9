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
	void PrintOutput();  // cppcheck-suppress unusedFunction

};