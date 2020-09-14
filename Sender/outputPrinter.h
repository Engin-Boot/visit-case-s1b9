#pragma once

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>

class Output_DatePrinter
{
private:
	int _month;
	int _year;

	std::string _date[3];

	void SplitDate(std::string& date_format);

public:
	Output_DatePrinter(int month, int year, std::string& date_format);
	std::string FirstField();
	std::string SecondField();
	std::string ThirdField();


};

void PrintDateString(std::string& date_format, int date, int month, int year);
void PrintTwoDigits(int number);
std::vector<std::string> SplitDate(std::string& date_format);


