#pragma once
#define RECEIVER_TEST
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
	int getHour();
	int getMinute();
	int getMonth();
	int getYear();

};

