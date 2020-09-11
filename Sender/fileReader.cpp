#include"fileReader.h"

FileReader::FileReader(std::string filePathName):_fileName("SafeFile.csv")
{
	_filePtr.open(filePathName);
	if (_filePtr.good())
		_fileName = filePathName;
	else
		_filePtr.open(_fileName);
}
std::string FileReader::GetFileName() { return _fileName; }
