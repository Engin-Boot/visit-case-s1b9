#include "receiver.h"

Data::Data():date(01),month(01),year(2000),hour(00),minute(00) {}

Data::Data(int dt, int mth, int yr , int hr, int min): date(dt), month(mth), year(yr), hour(hr), minute(min){}


void Data::checkDataformat_AddtoBuffer(std::string senderFormat, std::string dataFormat, std::vector<int> result, int date, int month, int year, int hour,int min)
{

	if (senderFormat.compare(dataFormat) != 0)
	{
		return;
	}
	Data addToBuffer(result[date], result[month], result[year], result[hour], result[min]);
	storeBufferFootfall.push_back(addToBuffer);
}

void Data::getSenderData()
{
	std::string senderString,senderFormat;
	getline(cin, senderFormat);
	cout <<"Footfall Data format used by Sender"<< senderFormat<<endl;
	while (getline(cin, senderString))
	{
		if (senderString =="")
			break;

		cout << "Time when a visitor enters" << senderString << endl;
		storeInBuffer(senderFormat, senderString);
	}
}

void Data::storeInBuffer(std::string senderFormat, std::string senderString)
{
	int date,month,year,hr,min;
	date = month = year = hr = min = 0;
	int reciever_parameter = 0;
	 std::vector<int> result;
	stringstream sso(senderString);

	while (sso >> reciever_parameter)
	{
		result.push_back(reciever_parameter);
	}

	//For Format1
	string dataFormat1 = "dd mm yyyy hr mn";
	
	date = 0, month = 1, year = 2, hr = 3, min = 4;
	checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

	//For Format2
	string dataFormat2 = "mm dd yyyy hr mn";
	date = 1, month = 0, year = 2, hr = 3, min = 4;
	checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

	//Format3
	string dataFormat3 = "yyyy mm dd hr mm";
	date = 2, month = 1, year = 0, hr = 3, min = 4;
	checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);

	//Format4
	string dataFormat4 = "yyyy dd mm hr mm";
	date = 1, month = 2, year = 0, hr = 3, min = 4;
	checkDataformat_AddtoBuffer(senderFormat, dataFormat1, result, date, month, year, hr, min);
}


//
//void Receiver::getAvgHourlyfootfall()
//{
//	
//
//}
//void  Receiver::getAvgDailyfootfall() {}
//void  Receiver::getPeekDailyfootfallMontly() {}

int main()
{
	Data obj1;
	obj1.getSenderData();

	return 0;
}