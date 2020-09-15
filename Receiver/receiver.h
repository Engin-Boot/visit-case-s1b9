#pragma once
#include "Data.h"

class Receiver
{
private:
	int hours;
	int days;
	int peakValue=0;
	int peakdate=0;
	vector<Data> BufferFootfall;
	vector<vector<int>> visitCount;
	vector<float> hourlyAvgFootfall;
	vector<float> dailyAvgFootfall;

public:
	Receiver();
	Receiver(int,int);

	/*int getDays();
	int getHours();
	
	void setDays(int);
	void setHours(int);*/


	void getSenderData();
	void storeInBuffer(std::string&, std::string&);
	
	void clearBuffer();
	void storeCountInVector();

	
	
	void storeAvgForPreviousMonth();

	void getAvgHourlyfootfall();
	void getAvgHourlyfootfall(int,int);
	void getAvgDailyfootfall();
	int getPeekDailyfootfallMontly();

	void StoreInCSV();

};