#include "receiver.h"
#include <map>
#include<sstream>
#include<fstream>
#include<iomanip>

using namespace std;

std::vector<int> DaysInTheMonth = {31,28,31,30,31,30,31,31,30,31,30,31};

Data::Data()
{
	this->date = 01;
	this->month = 01;
	this->year = 2000;
	this->hour = 0;
	this->minute = 0;
}

Data::Data(int dt, int mth, int yr , int hr, int min)
{
	this->date = dt;
	this->month = mth;
	this->year = yr;
	this->hour = hr;
	this->minute = min;
}


int Data::getHour()
{
	return this->hour;
}

int Data::getDate()
{
	return this->date;
}

int Data::getMonth()
{
	return this->month;
}
int Data::getYear()
{
	return this->year;
}
int Data::getMinute()
{
	return this->minute;
}

int Receiver::getDays()
{
	return this->days;
}
int Receiver::getHours()
{
	return this->hours;
}

int Receiver::getPeekValue()
{
	return this->peakValue;
}

int Receiver::getPeakDateValue()
{
	return this->peakdate;
}

Receiver::Receiver()
{
	this->hours = 24;
	this->days = 31;
	for (int hour = 0; hour < hours+1; hour++)
	{

		vector<int> temp_hours(days, 0);
		this->visitCount.push_back(temp_hours);
	}
}

Receiver::Receiver(int hr,int noofDays)
{
	this->hours = hr;
	this->days = noofDays;
	for (int hour = 0; hour < hours+1; hour++)
	{
		vector<int> temp_hours(days,0);
		this->visitCount.push_back(temp_hours);
	}
}

vector<Data> Receiver::getBuffer()
{
	return this->BufferFootfall;
}

std::vector<std::vector<int>> Receiver::getVisitCount()
{
	return this->visitCount;
}

void Receiver::setVisitCount(int hour, int date,int value)
{
	visitCount[hour][date] = value;
}

std::vector<float> Receiver::gethourAvg()
{
	return this->hourlyAvgFootfall;
}

std::vector<float> Receiver::getDailyAvg()
{
	return dailyAvgFootfall;
}



int checkMonth(int month)
{
	if (month < 1 || month>12)
	{
		return 0;
	}
	/*if (leapYear(BufferFootfall[0].year))
	{
		return DaysInTheMonthForLeapYear[month];
	}*/
	return DaysInTheMonth[month - 1];
}


void Receiver::clearBuffer()
{
	if (!BufferFootfall.empty())
	{
		storeCountInVector();
		BufferFootfall.clear();
	}

}

void Receiver::storeCountInVector()
{
	int hours = 24;
	

	for (unsigned int i = 1; i <= BufferFootfall.size(); i++)
	{
		int hour = BufferFootfall[i-1].getHour();
		int date = BufferFootfall[i-1].getDate();
		visitCount[hour][date -1] = visitCount[hour][date - 1] + 1;
		visitCount[hours][date - 1] = visitCount[hours][date - 1] + 1; 
	}
	
}

void split(vector<string>& result, string s1, char sep) {
	string val = "";
	for (unsigned int i = 0; i < s1.length(); i++)
	{
		string x(1, s1[i]);
		if (s1[i] == sep) {
			result.push_back(val);
			val = "";
		}
		else {
			val = val + x;
		}
	}
	result.push_back(val);
}

void Receiver::getSenderData()
{
	string senderString,senderFormat;
	getline(cin, senderFormat);
	cout <<"Footfall Data format used by Sender: "<< senderFormat<<endl;

	while (getline(cin, senderString))
	{
		if (senderString == "")
			break;

		storeInBuffer(senderFormat, senderString);
	}
}

void Receiver::storeInBuffer(string& senderFormat,string& senderString)
{
	map<string, int> recievedData;
	
	vector<string>senderFormatVector;
	vector<string>senderStringVector;

	split(senderFormatVector, senderFormat,' ');
	split(senderStringVector, senderString, ' ');

	for (unsigned int i = 0; i < senderFormatVector.size(); i++)
	{
		recievedData[senderFormatVector[i]] = stoi(senderStringVector[i]);
	}

	Data addToBuffer(recievedData["dd"], recievedData["mm"], recievedData["yyyy"], recievedData["hh"], recievedData["mn"]);
	BufferFootfall.push_back(addToBuffer);

	if (BufferFootfall.size() >=5)
	{
		storeCountInVector();
		BufferFootfall.clear();
	}
}


void Receiver::getAvgHourlyfootfall(int noofHours,int noofDays)
{
	for (int hour = 0; hour < noofHours; hour++)
	{
		float sum = 0;
		for (int day = 0; day < noofDays; day++)
		{
			sum = sum + visitCount[hour][day];
		}
		hourlyAvgFootfall.push_back(sum/noofDays);
		cout <<"Avg. Count for Hour: "<<setw(2)<<setfill('0')<<hour<<" is: "<< hourlyAvgFootfall[hour] <<endl;
	}
	
}

void Receiver::getAvgDailyfootfall()
{
	cout << "		" << endl;
	for (unsigned int day= 0; day < 7; day++)
	{
		float sum,count;
		sum = count = 0;
		for (unsigned int i = day; i < visitCount[0].size(); i = i + 7)
		{
			sum = sum + visitCount[24][i];
			count++;
		}
		dailyAvgFootfall.push_back(sum / count);
		cout << "Avg. Count for Day : " << setw(2) << setfill('0')<< day << " is: " << dailyAvgFootfall[day] << endl;
	}
	
}

int Receiver::getPeekDailyfootfallMontly() 
{
	int date = 1;
	int max = visitCount[24][0];
	for (unsigned int day = 0; day < visitCount[0].size(); day++)
	{
		if (visitCount[24][day] > max)
		{
			max = visitCount[24][day];
			date = day + 1;
		}
	}
	peakValue = max;
	peakdate = date;
	cout << "		" << endl;
	cout << "Date on which we will get maximum count: " << setw(2) << setfill('0') << date << " maximum value " << max << endl;
	return max;
}

void Receiver::StoreInCSV()
{
	fstream MyFile;
	MyFile.open("Receiver.csv", ios::out | ios::app);

	MyFile <<"Hour"<<","<<"Average"<<"\n";
	
	for (unsigned int i = 0; i < hourlyAvgFootfall.size(); i++)
	{
		MyFile << i <<","<< hourlyAvgFootfall[i] <<"\n";
	}
	MyFile << "\n";
	MyFile << "Day" << "," << "Average"<< "\n";
	
	for (unsigned int i = 0; i < dailyAvgFootfall.size(); i++)
	{
		MyFile << i << "," << dailyAvgFootfall[i] << "\n";
	}
	MyFile << "\n";
	MyFile << "Month" << "," << "Value" << "\n";
	MyFile << peakdate << "," << peakValue << "\n";
	MyFile.close();
}

vector<int> getMonthandYear(string str)
{
	
	vector<int> result;
	stringstream sso(str);
	int month_year = 0;
	while (sso >> month_year)
	{
		result.push_back(month_year);
	}
	return result;
}

#ifndef RECEIVER_TEST

int main()
{
	//First line of Input is the Month and Year which we need to consider
	string str;
	getline(cin, str);
	vector<int> result = getMonthandYear(str);

	int month = checkMonth(result[0]);

	Receiver obj1(24, month);
	obj1.getSenderData();

	obj1.clearBuffer();

	obj1.getAvgHourlyfootfall(24, 31);
	obj1.getAvgDailyfootfall();
	obj1.getPeekDailyfootfallMontly();
	//cout << getPeek<<endl;
	obj1.StoreInCSV();

	return 0;
}

#endif // !1







