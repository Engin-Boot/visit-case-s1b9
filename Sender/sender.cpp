#include<iostream>
#include<fstream>
#include <string>


using namespace std;
int main()
{
	std::ifstream f("output.txt");
	if (f.is_open())
		std::cout << f.rdbuf();

}

