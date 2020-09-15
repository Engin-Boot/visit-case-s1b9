#include"test-all.h"

#ifndef TEST_ALL

#include"monthlyTimestamps.h"

int main()
{
	std::string fileName = "./test-data/input.csv";
	MonthlyTimestamps aug(fileName);
	aug.PrintOutput();

	return 0;
}

#endif