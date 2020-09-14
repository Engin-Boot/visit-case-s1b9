#pragma once
#include "Data.h"

class Receiver
{
private:
	int hours;
	int days;
	vector<Data> BufferFootfall;
	vector<vector<int>> visitCount;
	vector<float> hourlyAvgFootfall;
	vector<float> dailyAvgFootfall;

public:
	Receiver();
	Receiver(int);

	int getDays();
	int getHours();

	void setDays(int);
	void setHours(int);


	void getSenderData();
	void storeInBuffer(std::string, std::string);
	//void displayBuffer();
	void storeCountInVector();
	int checkMonth(int);

	void getAvgHourlyfootfall(int,int);
	void getAvgDailyfootfall();
	int getPeekDailyfootfallMontly();

	void StoreInCSV();

};