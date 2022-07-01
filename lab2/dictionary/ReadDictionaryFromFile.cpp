#include "dictionary.h"
// название модуля
using namespace std;
// протестирвоать
// принять имя файла по константной сылке
bool ReadDictionaryFromFile(string fileName, Dictionary& dictionary)
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
		string word;
		getline(file, word, SEPARATOR);
		string translatedWord;
		getline(file, translatedWord);
		dictionary.emplace(word, translatedWord);
	}
	if (file.bad())
	{
		cout << "Failed to read data from " << fileName << endl;
		
		return false;
	}

	return true;
}