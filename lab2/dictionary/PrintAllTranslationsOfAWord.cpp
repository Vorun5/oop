#include "dictionary.h"

using namespace std;

// выдавать множество
bool PrintAllTranslationsOfAWord(const string& word, const Dictionary& dictionary)
{
	bool translationsFound = false;
	for (auto translatedWord = dictionary.lower_bound(word);
		 translatedWord != dictionary.end() && translatedWord->first == word;
		 translatedWord++)
	{
		if (translationsFound)
		{
			cout << ", ";
		}
		cout << translatedWord->second;
		translationsFound = true;
	}
	if (translationsFound)
	{
		cout << endl;
	}
	return translationsFound;
}