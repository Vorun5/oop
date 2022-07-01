#include "wordFilter.h"

using namespace std;

string PassAWordThroughCensorship(const string& word, const set<string>& forbiddenWords)
{
	if (!word.empty())
	{
		string lowerCaseWord;
		transform(word.begin(), word.end(), back_inserter(lowerCaseWord),
			[](unsigned char ch) { return static_cast<char>(::tolower(ch)); });
		if (forbiddenWords.find(lowerCaseWord) != forbiddenWords.end())
		{
			return "";
		}
	}
	return word;
}