#include "wordFilter.h"

using namespace std;

void ReadFromStreamLineByLineAndFilter(istream& stream, const set<string>& forbiddenWords)
{
	while (!stream.eof())
	{
		string text;
		getline(stream, text);
		text = FilterForbiddenWords(text, forbiddenWords);
		cout << text << endl;
		cout << "--------------------------------" << endl;
	}
}

int main()
{
	set<string> forbiddenWords;
	if (!ReadWordsFromFile("words.txt", forbiddenWords))
	{
		return 1;
	}
	ReadFromStreamLineByLineAndFilter(cin, forbiddenWords);
	return 0;
}