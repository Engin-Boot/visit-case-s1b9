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

void Output_DatePrinter::Print_Date(int date)
{
	std::map<std::string, int> field_to_value;

	field_to_value.insert(std::pair<std::string, int>("dd", date));
	field_to_value.insert(std::pair<std::string, int>("mm", _month));
	field_to_value.insert(std::pair<std::string, int>("yyyy", _year));

	PrintAtleastTwoDigits(field_to_value.find(_date[0])->second);
	std::cout << " ";
	PrintAtleastTwoDigits(field_to_value.find(_date[1])->second);
	std::cout << " ";
	PrintAtleastTwoDigits(field_to_value.find(_date[2])->second);

}

std::string Output_DatePrinter::FirstField() { return _date[0]; }
std::string Output_DatePrinter::SecondField() { return _date[1]; }
std::string Output_DatePrinter::ThirdField() { return _date[2]; }

void PrintAtleastTwoDigits(int number)
{
	std::cout << std::setw(2) << std::setfill('0') << number;
}