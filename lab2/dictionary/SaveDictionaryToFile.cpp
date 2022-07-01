#include "dictionary.h"

using namespace std;
// константная ссылка
bool SaveDictionaryToFile(string fileName, const Dictionary& dictionary)
{
	ofstream file;
	file.open(fileName);
	if (!file.is_open())
	{
		cout << "Failed to open '" << fileName << "' for writing\n";
		return false;
	}
	for (const auto& [word, translatedWord] : dictionary)
	{
		if (!word.empty() && !translatedWord.empty())
		{
			file << word << SEPARATOR << translatedWord << endl;
		}
	}
	if (!file.flush())
	{
		cout << "Failed to write data to " << fileName << endl;
		return false;
	}
	return true;
}
