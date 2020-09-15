#include"fileReader.h"

std::vector<std::string> safe_lines
= { "Safe,file,not,present","default,values,loaded",
"1,1","2,1","3,1","4,1","5,1","6,1","7,1","8,1","9,1","10,1",
"11,1","12,1","13,1","14,1","15,1","16,1","17,1","18,1","19,1","20,1",
"21,1","22,1","23,1","24,1","25,1","26,1","27,1","28,1","29,1","30,1","31,1" };

FileReader::FileReader(std::string filePathName) :_fileName("./Sender/SafeFile.csv"), ReadIsGood(false)
{
	std::ifstream tempPtr;
	try
	{
		tempPtr.open(filePathName);
		if (tempPtr.good())
			_fileName = filePathName;
		else throw "Invalid file path!";
	}
	catch (const char* message)
	{
		tempPtr.close();
		std::cerr << message << std::endl;
	}
	
	tempPtr.close();
	ReadIsGood = ReadFile();
}

bool FileReader::ReadFile()
{
	try
	{
		_filePtr.open(_fileName);
		if (!_filePtr.good())
			throw "Could not open file!";
		Read();
		return true;
	}
	catch (const char* message)
	{
		std::cerr << message << std::endl;
		_fileLines = safe_lines;
		return false;
	}

}
void FileReader::Read()
{
	while (!_filePtr.eof())
	{
		std::string line;
		getline(_filePtr, line, '\n');
		_fileLines.push_back(line);
	}
}

std::vector<std::string> FileReader::GetFileLines() { return _fileLines; }
