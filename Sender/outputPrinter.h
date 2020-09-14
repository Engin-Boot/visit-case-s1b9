#pragma once

#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<map>
#include<iterator>

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

	void Print_Date(int);

};

void PrintTime(int hour, int min);

void PrintAtleastTwoDigits(int number);



