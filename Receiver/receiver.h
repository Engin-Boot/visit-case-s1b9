#pragma once
#include "Data.h"

class Receiver
{
private:
	int hours;
	int days;
	int peakValue = 0;
	int peakdate = 0;
	std::vector<Data> BufferFootfall;
	std::vector<std::vector<int>> visitCount;
	std::vector<float> hourlyAvgFootfall;
	std::vector<float> dailyAvgFootfall;

public:
	Receiver();
	Receiver(int, int);

	int getDays();
	int getHours();

	int getPeekValue();
	int getPeakDateValue();

	std::vector<Data> getBuffer();

	std::vector<std::vector<int>> getVisitCount();
	void setVisitCount(int, int, int);

	std::vector<float> gethourAvg();
	std::vector<float> getDailyAvg();

	void getSenderData();
	void storeInBuffer(std::string&, std::string&);

	void clearBuffer();
	void storeCountInVector();

	void getAvgHourlyfootfall();
	void getAvgHourlyfootfall(int, int);
	void getAvgDailyfootfall();
	int getPeekDailyfootfallMontly();

	void StoreInCSV();
};

std::vector<int> getMonthandYear(std::string);
int checkMonth(int);
void split(std::vector<std::string>&, std::string, char);
