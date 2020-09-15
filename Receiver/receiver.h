#pragma once
#include "Data.h"

class Receiver
{
private:
	int hours;
	int days;
	int peakValue=0;
	int peakdate=0;
	std::vector<Data> BufferFootfall;
	std::vector<std::vector<int>> visitCount;
	std::vector<float> hourlyAvgFootfall;
	std::vector<float> dailyAvgFootfall;

public:
	Receiver();
	Receiver(int,int);

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

std::vector<int> getMonthandYear();
int checkMonth(int);
void split(std::vector<std::string>&, std::string, char);
