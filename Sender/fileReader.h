#pragma once
#include"test-all.h"
#include<fstream>
#include<vector>
#include<string>


extern std::vector<std::string> safe_lines;

class FileReader
{
private:
	std::string _fileName;
	std::ifstream _filePtr;

	std::vector<std::string> _fileLines;
	
	bool ReadFile();
	void Read();

public:
	bool ReadIsGood;
	explicit FileReader(std::string);
	std::vector<std::string> GetFileLines();

};