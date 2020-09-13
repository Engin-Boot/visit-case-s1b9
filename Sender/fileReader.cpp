#include"fileReader.h"

FileReader::FileReader(std::string filePathName) :_fileName("./Sender/SafeFile.csv"), ReadIsGood(false)
{
	std::ifstream tempPtr;
	tempPtr.open(filePathName);
	if (tempPtr.good())
		_fileName = filePathName;

	tempPtr.close();

	ReadIsGood = ReadFile();
}

//std::string FileReader::GetFileName() { return _fileName; }

bool FileReader::ReadFile()
{
	_filePtr.open(_fileName);

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

std::vector<std::string> FileReader::GetFileLines() { return _fileLines; }