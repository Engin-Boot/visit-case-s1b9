#pragma once
#include"test-all.h"
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

	void SplitDate(const std::string& date_format);

public:
	Output_DatePrinter(int month, int year, std::string& date_format);
	void Print_FirstLine();
	void Print_Date(int);

};

void PrintFormatLine(const std::string& format);

void PrintTime(int hour, int min);

void PrintAtleastTwoDigits(int number);



