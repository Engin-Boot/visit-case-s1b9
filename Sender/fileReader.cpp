#include"fileReader.h"

FileReader::FileReader(std::string filePathName):_fileName("./Sender/SafeFile.csv")
{
	_filePtr.open(filePathName);
	if (_filePtr.good())
		_fileName = filePathName;
	
	_filePtr.close();
	_filePtr.open(_fileName);
}

std::string FileReader::GetFileName() { return _fileName; }

bool FileReader::ReadFile()
{
	if (_filePtr.good())
	{
		while (!_filePtr.eof())
		{
			std::string line;
			getline(_filePtr, line, '\n');
			_fileLines.push_back(line);
		}
		return true;
	}
	return false;
}
bool FileReader::ReadFileIsGood() { return ReadFile(); }

std::vector<std::string> FileReader::GetFileLines() { return _fileLines; }