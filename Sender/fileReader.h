#include<fstream>
#include<vector>
#include<string>

class FileReader
{
private:
	std::string _fileName;
	std::ifstream _filePtr;

	std::vector<std::string> _fileLine;
public:
	FileReader(std::string);
	std::string GetFileName();
};