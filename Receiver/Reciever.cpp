#include "receiver.h"
#include <map>
#include<fstream>

std::vector<int> DaysInTheMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
std::vector<int> DaysInTheMonthForLeapYear = {31,29,31,30,31,30,31,31,30,31,30,31};

Data::Data():date(01),month(01),year(2000),hour(00),minute(00) {}

Data::Data(int dt, int mth, int yr , int hr, int min): date(dt), month(mth), year(yr), hour(hr), minute(min){}

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
int Data::getHour()
{
	return this->hour;
}
int Data::getMinute()
{
	return this->minute;
}

void Data::setDate(int date)
{
	this->date = date;
}
void Data::setMonth(int month)
{
	this->month = month;
}
void Data::setYear(int year)
{
	this->year = year;
}
void Data::setHour(int hour)
{
	this->hour = hour;
}
void Data::setMinute(int min)
{
	this->minute = min;
}

int Receiver::getDays()
{
	return this->days;
}
int Receiver::getHours()
{
	return this->hours;
}

void Receiver::setDays(int days)
{
	this->days = days;
}
void Receiver::setHours(int hours)
{
	this->hours = hours;
}

Receiver::Receiver():hours(25),days(31) 
{
	for (int i = 0; i <= hours; i++)
	{

		vector<int> temp_hours(days, 0);
		this->visitCount.push_back(temp_hours);
	}
}

int Receiver::checkMonth(int month)
{

	/*if (leapYear(BufferFootfall[0].year))
	{
		return DaysInTheMonthForLeapYear[month];
	}*/
	return DaysInTheMonth[month-1];
}

//Just enter the number of month and the corresponding 2D vector  of (24Hour+ 1 to store total daily count)25*noofdays will be created
Receiver::Receiver(int month)		
{
	 int noofDays = 31;
	 noofDays= checkMonth(month);
	 cout << "No Of Days in this month=" << noofDays<<endl;
	int hours = 24;
	//Added 24 rows to the visit counter
	for (int i = 0; i <= hours; i++)
	{
		vector<int> temp_hours(noofDays,0);
		this->visitCount.push_back(temp_hours);
	}
}



void Receiver::storeCountInVector()
{
	int hours = 24;
	//One extra row is added to store the total of visits in that day

	for (unsigned int i = 1; i <= BufferFootfall.size(); i++)
	{
		int hour = BufferFootfall[i-1].getHour();
		int date = BufferFootfall[i-1].getDate();
		visitCount[hour][date -1] = visitCount[hour][date - 1] + 1;
		visitCount[hours][date - 1] = visitCount[hours][date - 1] + 1; 
		//cout <<"hour"<<hour<<"date: "<<date<<visitCount[hours][date - 1]<<" "<<endl;
	}
	
	/*for (int days= 0; days < 30;days++)
	{
		for (int  hours = 0; hours < 24; hours++)
		{
			cout << visitCount[hours][days]<<" ";
		}

	}*/
	//visitorCount.insert(visitCount);
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
	cout << "Enter the format: ";
	string senderString,senderFormat;
	getline(cin, senderFormat);
	cout <<"Footfall Data format used by Sender "<< senderFormat<<endl;

	while (getline(cin, senderString))
	{
		if (senderString =="")
			break;

		//cout << "Time when a visitor enters" << senderString << endl;
		storeInBuffer(senderFormat, senderString);
	}
}

void Receiver::storeInBuffer(string senderFormat,string senderString)
{
	/*int date,month,year,hr,min;
	date = month = year = hr = min = 0;*/

	/*int data_parameter = 0;

	 std::vector<int> result;
	stringstream sso(senderString);

	while (sso >> data_parameter)
	{
		result.push_back(data_parameter);
	}*/

	//To map the Sender Format Data accordingly

	map<string, int> recievedData;
	
	vector<string>senderFormatVector;
	vector<string>senderStringVector;

	split(senderFormatVector, senderFormat,' ');
	split(senderStringVector, senderString, ' ');

	for (unsigned int i = 0; i < senderFormatVector.size(); i++)
	{
		recievedData[senderFormatVector[i]] = stoi(senderStringVector[i]);
	}

	
	Data addToBuffer(recievedData["dd"], recievedData["mm"], recievedData["yyyy"], recievedData["hr"], recievedData["mn"]);
	BufferFootfall.push_back(addToBuffer);

	//clear buffer for change in month

	if (BufferFootfall.size() >=1)
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
			//cout << sum<<" ";
		}
		hourlyAvgFootfall.push_back(sum);
		//cout <<"Avg. Count for"<<hour<<"is: "<< hourlyAvgFootfall[hour] <<endl;
	}
}

void Receiver::getAvgDailyfootfall()
{
	//int noofdays = BufferFootfall[0].getMonth();
	for (unsigned int day= 0; day < 7; day++)
	{
		int sum,count;
		sum = count = 0;
		for (unsigned int i = day; i < visitCount[0].size(); i = i + 7)
		{
			sum = sum + visitCount[24][i];
			count++;
		}
		dailyAvgFootfall.push_back(sum / count);
	}
}

int Receiver::getPeekDailyfootfallMontly() 
{
	
	int max = visitCount[24][0];
	for (unsigned int day = 0; day < visitCount[0].size(); day++)
	{
		if (visitCount[24][day] > max)
		{
			max = visitCount[24][day];
		}
	}
	cout << max;
	return max;
}

void Receiver::StoreInCSV()
{
	fstream MyFile;
	MyFile.open("receiverReport3.csv", ios::out | ios::app);
	MyFile << "Hour" << ","<< "Average"<<"\n";
	
	for (int i = 12; i < 30; i++)
	{
		
		MyFile << i <<" ,"<< i <<"\n";
	}
	/*for (int i = 0; i < hourlyAvgFootfall.size(); i++)
	{
		string str = i + "-" + i + 1;
		MyFile << str << hourlyAvgFootfall[i];
	}*/
	MyFile.close();
}


int main()
{
	//getline(cin,)
	string str;
	getline(cin, str);

	Receiver obj1(stoi(str));
	obj1.getSenderData();
	
	obj1.getAvgHourlyfootfall(4, 30);
	obj1.getAvgDailyfootfall();
	int getPeek=obj1.getPeekDailyfootfallMontly();
	cout << getPeek<<endl;
	obj1.StoreInCSV();

	return 0;
}











//string dataFormat1 = "dd mm yyyy hr mn";
//
//date = 0, month = 1, year = 2, hr = 3, min = 4;
//checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

////For Format2
//string dataFormat2 = "mm dd yyyy hr mn";
//date = 1, month = 0, year = 2, hr = 3, min = 4;
//checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

////Format3
//string dataFormat3 = "yyyy mm dd hr mm";
//date = 2, month = 1, year = 0, hr = 3, min = 4;
//checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

////Format4
//string dataFormat4 = "yyyy dd mm hr mm";
//date = 1, month = 2, year = 0, hr = 3, min = 4;
//checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

//void Receiver::checkDataformat_AddtoBuffer(string senderFormat, string dataFormat, vector<int> result, int date, int month, int year, int hour,int min)
//{
//
//	if (senderFormat.compare(dataFormat) != 0)
//	{
//		return;
//	}
//	Data addToBuffer(result[date], result[month], result[year], result[hour], result[min]);
//	BufferFootfall.push_back(addToBuffer);
//}