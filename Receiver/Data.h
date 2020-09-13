#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<sstream>
using namespace std;

class Data
{
private:
	std::vector<Data> storeBufferFootfall;
	int date=0;
	int month=0;
	int year=0;
	int hour=0;
	int minute=0;
	
public:
	Data();
	Data(int, int, int, int, int);

	void getSenderData();
	void storeInBuffer(std::string, std::string);
	void displayBuffer();
	void checkDataformat_AddtoBuffer(std::string, std::string,std::vector<int>,int,int,int,int,int);
};

