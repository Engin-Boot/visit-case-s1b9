#include"outputPrinter.h"

Output_DatePrinter::Output_DatePrinter(int month, int year, std::string& date_format): _month(month), _year(year), _date{"dd","mm","yyyy"}
{
	SplitDate(date_format);
}
 
void Output_DatePrinter::SplitDate(std::string& date_format)
{
	unsigned int date_field_count = 0;
	std::string field = "";
	 for (auto i : date_format)
	 {
		 if (i == ' ')
		 {
			 _date[date_field_count] = field;
			 field = "";
			 date_field_count++;
		 }
		 else
			 field += i;
	 }
	 _date[date_field_count] = field;
}

std::string Output_DatePrinter::FirstField() { return _date[0]; }
std::string Output_DatePrinter::SecondField() { return _date[1]; }
std::string Output_DatePrinter::ThirdField() { return _date[2]; }

void PrintDateString(std::string& date_format, int date, int month, int year)
{

}
void PrintTwoDigits(int number)
{
	std::cout << std::setw(2) << std::setfill('0') << number;
}