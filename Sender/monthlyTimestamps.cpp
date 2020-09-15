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

void MonthlyTimestamps::PrintOutput() // cppcheck-suppress unusedFunction
{
	const std::string output_format = _data.GetOutputFormat();
	std::string date_format = _data.DateFormat();
	int month = _data.GetMonth();
	int year = _data.GetYear();

	Output_DatePrinter printer(month, year, date_format);
	
	printer.Print_FirstLine();
	PrintFormatLine(output_format);

	for (int date_minus_one = 0; (unsigned int)date_minus_one < _timestamps.size(); date_minus_one++)
	{
		std::vector<int> hours = _timestamps[date_minus_one].GetDailyHours();
		std::vector<int> minutes = _timestamps[date_minus_one].GetDailyMinutes();

		for (int i = 0; (unsigned int)i < hours.size(); i++)
		{
			printer.Print_Date(date_minus_one + 1);
			std::cout << " ";
			PrintTime(hours[i], minutes[i]);
			std::cout << std::endl;
		}
	}
}
