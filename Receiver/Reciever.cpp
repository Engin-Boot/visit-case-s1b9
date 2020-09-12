#include "receiver.h"
#include "Data.h"
#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
#include<sstream>
#include<queue>

using namespace std;

Data::Data():date(01),month(01),year(2000),hour(00),minute(00) {}

Data::Data(int dt, int mth, int yr , int hr, int min): date(dt), month(mth), year(yr), hour(hr), minute(min){}



void Data::getSenderData()
{
	std::string senderString,senderFormat;
	getline(cin, senderFormat);

	while (getline(cin, senderString))
	{

		cout << senderString;
		storeInBuffer(senderFormat, senderString);
	}
}

void Data::storeInBuffer(std::string senderFormat, std::string senderString)
{
	int reciever_parameter = 0;
	 std::vector<int> result;
	stringstream sso(senderString);

	while (sso >> reciever_parameter)
	{
		result.push_back(reciever_parameter);
	}
	if (senderFormat.compare("dd mm yyyy hr mm")==0)
	{
		Data addToBuffer(result[0], result[1], result[2], result[3], result[4]);
		storeBufferFootfall.push_back(addToBuffer);
	}
	else if (senderFormat.compare("mm dd yyyy hr mm") == 0)
	{
		Data addToBuffer(result[1], result[0], result[2], result[3], result[4]);
		storeBufferFootfall.push_back(addToBuffer);
	}
	else if (senderFormat.compare("yyyy mm dd hr mm") == 0)
	{
		Data addToBuffer(result[2], result[1], result[0], result[3], result[4]);
		storeBufferFootfall.push_back(addToBuffer);
	}
	else if (senderFormat.compare("yyyy dd mm hr mm") == 0)
	{
		Data addToBuffer(result[2], result[0], result[1], result[3], result[4]);
		storeBufferFootfall.push_back(addToBuffer);
	}
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

	return 0;
}