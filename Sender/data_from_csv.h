#pragma once
#include"test-all.h"
#include"fileReader.h"
#include"monthlyData.h"
#include"outputFormat.h"
#include<vector>
#include<string>
#include<sstream>

#define COMMA ','

class DataFrom_csv
{
private:
	OutputFormat _output_format;
	MonthlyData _daily_footfalls;
	FileReader _csvReader;

	std::vector<std::string> _file_lines;
	void FormatLines_csv();
	void UpdateOutputFormat(const char*);
	void UpdateMonthAndYear();
	std::vector<int> Get_FootfallValues();
	std::vector<int> Calculate_FootfallValues();
	bool FilelinesAreInvalid();
	void UpdateFootfallValues();

	std::vector<int> Safety_values(int);

public:
	explicit DataFrom_csv(std::string&);
	std::string GetOutputFormat();
	std::string DateFormat();
	int GetMonth();
	int GetYear();
	std::vector<int> GetFootfallValues();
};

std::vector<int> SplitString(std::string&);
std::vector<int> Split(std::string& csv_line);