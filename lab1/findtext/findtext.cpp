#include <fstream>
#include <functional>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

using FindStringCallback = function<void(int lineIndex, const string& line, size_t foundPos)>;

struct Args
{
	string inputFileName;
	string textToSearch;
};

bool FindStingInStream(string& fileName, const string& textToSearch, const FindStringCallback& callback = FindStringCallback())
{

	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Failed to open '" << fileName << "' for reading\n";
		return false;
	}

	string line;
	bool found = false;

	for (int lineIndex = 1; getline(file, line); ++lineIndex)
	{
		auto pos = line.find(textToSearch);
		if (pos != string::npos)
		{
			found = true;
			callback(lineIndex, line, pos);
		}
	}

	if (file.bad())
	{
		cout << "Failed to read data from input file\n";
		return false;
	}

	if (!found)
	{
		cout << "No string found" << endl;
	}

	return true;
}

optional<Args> ParseArgs(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n";
		cout << "Usage: findtext.exe <input file name> <text to search>";
		return nullopt;
	}
	Args args;
	args.inputFileName = argv[1];
	args.textToSearch = argv[2];
	if (args.textToSearch == "")
	{
		cout << "Invalid data\n";
		cout << "Empty string to search\n";
		return nullopt;
	}
	if (args.inputFileName == "")
	{
		cout << "Invalid data\n";
		cout << "Empty intput file name\n";
		return nullopt;
	}
	return args;
}

void PrintFoundLineIndex(int lineIndex, const string& /*line*/, size_t /*foundPos*/)
{
	cout << lineIndex << endl;
}

int main(int argc, char* argv[])
{
	auto args = ParseArgs(argc, argv);
	if (!args)
	{
		return 1;
	}

	if (!FindStingInStream(args->inputFileName, args->textToSearch, PrintFoundLineIndex))
	{
		return 1;
	}

	return 0;
}
