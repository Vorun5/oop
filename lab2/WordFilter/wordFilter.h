#include <fstream>
#include <iostream>
#include <optional>
#include <set>
#include <string>
#include <algorithm>

std::string PassAWordThroughCensorship(const std::string&, const std::set<std::string>&);

std::string FilterForbiddenWords(const std::string& text, const std::set<std::string>& forbiddenWords);

bool ReadWordsFromFile(std::string fileName, std::set<std::string>& words);