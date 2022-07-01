#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <windows.h>


const char SEPARATOR = '|';

using  Dictionary = std::multimap<std::string, std::string>;

bool PrintAllTranslationsOfAWord(const std::string& word, const Dictionary& dictionary);

bool ReadDictionaryFromFile(std::string fileName, Dictionary& dictionary);

bool SaveDictionaryToFile(std::string fileName, const Dictionary& dictionary);

void ReadRequestsFromStream(std::istream& stream, Dictionary& dictionary);