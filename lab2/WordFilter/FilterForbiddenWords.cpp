#include "wordFilter.h"

using namespace std;

string FilterForbiddenWords(const string& text, const set<string>& forbiddenWords)
{
	string word;
	string filteredString = "";

	for (unsigned char ch : text)
	{
		if (isalnum(ch))
		{
			word += ch;
		}
		else
		{
			filteredString += PassAWordThroughCensorship(word, forbiddenWords);
			word = "";
			filteredString += ch;
		}
	}

	filteredString += PassAWordThroughCensorship(word, forbiddenWords);

	return filteredString;
}