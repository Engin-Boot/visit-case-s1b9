#include"monthlyTimestamps.h"

int main()
{
	std::string fileName = "./test-data/input.csv";
	MonthlyTimestamps aug(fileName);
	aug.PrintOutput();

	return 0;
}