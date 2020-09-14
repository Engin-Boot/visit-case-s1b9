#include"monthlyTimestamps.h"

MonthlyTimestamps::MonthlyTimestamps(std::string& fileName):_data(fileName)
{
	UpdateDayTimestamps();
}

void MonthlyTimestamps::UpdateDayTimestamps()
{
	std::vector<int> footfalls = _data.GetFootfallValues();
	for (unsigned int i = 0; i < footfalls.size(); i++)
	{
		DayTimestamps value(footfalls[i]);
		_timestamps.push_back(value);
	}
}
std::vector<int> MonthlyTimestamps::GetHoursOn(int date)
{
	return _timestamps[date].GetDailyHours();
}
std::vector<int> MonthlyTimestamps::GetMinutesOn(int date)
{
	return _timestamps[date].GetDailyMinutes();
}