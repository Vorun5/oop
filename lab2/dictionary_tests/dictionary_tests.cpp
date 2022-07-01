#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../cath/catch.hpp"
#include "../dictionary/dictionary.h"

using namespace std;

SCENARIO("The word is not in the dictionary")
{
	Dictionary dictionary;
	dictionary.emplace("cat", "кот");
	dictionary.emplace("cat", "собака");
	dictionary.emplace("frog", "лягушка");
	REQUIRE(PrintAllTranslationsOfAWord("meat", dictionary) == false);
}

SCENARIO("Look for an empty word")
{
	Dictionary dictionary;
	dictionary.emplace("cat", "кот");
	dictionary.emplace("dog", "собака");
	dictionary.emplace("frog", "лягушка");
	REQUIRE(PrintAllTranslationsOfAWord("", dictionary) == false);
}

SCENARIO("The user wanted to save the new word")
{
	Dictionary dictionary;
	dictionary.emplace("cat", "кот");
	dictionary.emplace("dog", "собака");
	dictionary.emplace("frog", "лягушка");
	string dialog = "meat\nмясо\n...\ny";
	istringstream streamDialog(dialog);
	ReadRequestsFromStream(streamDialog, dictionary);
	REQUIRE(dictionary.find("meat") != dictionary.end());
}

SCENARIO("Output an existing word")
{
	Dictionary dictionary;
	dictionary.emplace("cat", "кот");
	dictionary.emplace("dog", "собака");
	dictionary.emplace("frog", "лягушка");
	REQUIRE(PrintAllTranslationsOfAWord("cat", dictionary) == true);
}

// больше тестов