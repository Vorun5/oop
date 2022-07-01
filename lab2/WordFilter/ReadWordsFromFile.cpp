#include "wordFilter.h"
using namespace std;

bool ReadWordsFromFile(string fileName, set<string>& words)
{
	ifstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Failed to open '" << fileName << "' for reading\n";
		return false;
	}
	while (!file.eof())
	{
		string buffer;
		if (file >> buffer)
		{
			transform(buffer.begin(), buffer.end(), buffer.begin(),
				[](unsigned char ch) { return static_cast<char>(::tolower(ch)); });
			words.insert(buffer);
		}
		else
		{
			break;
		}
	}

	if (file.bad())
	{
		cout << "Failed to read data from " << fileName << endl;
		return false;
	}

	return true;
}
