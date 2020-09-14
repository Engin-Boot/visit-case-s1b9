#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Data
{
private:
	int date=0;
	int month=0;
	int year=0;
	int hour=0;
	int minute=0;
	
public:
	
	Data();
	Data(int, int, int, int, int);
	int getDate();
	int getMonth();
	int getYear();
	int getHour();
	int getMinute();

	/*void setDate(int);
	void setMonth(int);
	void setYear(int);
	void setHour(int);
	void setMinute(int);*/
};

