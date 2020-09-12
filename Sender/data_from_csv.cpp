#include"data_from_csv.h"

DataFrom_csv::DataFrom_csv(std::string& fileName): _csvReader(fileName)
{	if (_csvReader.ReadIsGood)
	{	_file_lines = _csvReader.GetFileLines();
		FormatLines_csv(); 
	}
}
void DataFrom_csv::FormatLines_csv()	
//needs to be changed if input file format is different
{	UpdateOutputFormat();
	UpdateMonthAndYear();
	UpdateFootfallValues();
}
void DataFrom_csv::UpdateOutputFormat()
{	const char* outputFormat = _file_lines[0].c_str();
	_output_format.UpdateFormat(outputFormat);
}
void DataFrom_csv::UpdateMonthAndYear()
{	std::vector<int> month_and_year = SplitString(_file_lines[1]);
	_daily_footfalls.UpdateValues(month_and_year[0], month_and_year[1]);
}
void DataFrom_csv::UpdateFootfallValues()
{	std::vector<int> footfall_values = Get_FootfallValues();
	if (_daily_footfalls.GetNoOfDays() == (int)footfall_values.size())
		_daily_footfalls.UpdateFootfallPerDay(footfall_values);
}
std::vector<int> DataFrom_csv::Get_FootfallValues()
{	std::vector<int> footfall_values;
	for (int line_count = 3; line_count < (int)_file_lines.size(); line_count++)
	{	std::vector<int> split_data = SplitString(_file_lines[line_count]);
		footfall_values.push_back(split_data[1]);
	}
	return footfall_values;
}
std::string DataFrom_csv::GetOutputFormat() { return _output_format.Get_Format(); }
int DataFrom_csv::GetMonth() { return _daily_footfalls.GetMonth(); }
int DataFrom_csv::GetYear() { return _daily_footfalls.GetYear(); }
std::vector<int> DataFrom_csv::GetFootfallValues() 
{ return _daily_footfalls.GetFootfallPerDay(); }

std::vector<int> SplitString(std::string& csv_line)
//cant handle spaces in the csv file.
{	std::vector<int> split_data;
	std::stringstream stream_csv_line(csv_line);
		while (stream_csv_line.good())
	{	std::string column_value;
		std::getline(stream_csv_line, column_value, COMMA);
		split_data.push_back(stoi(column_value));
	}
	return split_data;
}