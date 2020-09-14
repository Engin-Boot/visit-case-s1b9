#include<fstream>
#include<vector>
#include<string>

class FileReader
{
private:
	std::string _fileName;
	std::ifstream _filePtr;

	std::vector<std::string> _fileLines;
	
	bool ReadFile();

public:
	bool ReadIsGood;
	explicit FileReader(std::string);
	std::vector<std::string> GetFileLines();
};