#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../cath/catch.hpp"
#include "../WordFilter/PassAWordThroughCensorship.cpp"
#include "../WordFilter/wordFilter.h"

using namespace std;

SCENARIO("Empty string")
{
	REQUIRE(FilterForbiddenWords("", set<string>{ "cat", "dog", "frog" }) == "");
}

SCENARIO("No forbidden words")
{
	REQUIRE(FilterForbiddenWords("I hope the test passes", set<string>{ "cat", "dog", "frog" }) == "I hope the test passes");
}

SCENARIO("Just a forbidden word")
{
	REQUIRE(FilterForbiddenWords("Cat", set<string>{ "cat", "dog", "frog" }) == "");
}

SCENARIO("Forbidden word sentence")
{
	REQUIRE(FilterForbiddenWords("Today i saw a frog", set<string>{ "cat", "dog", "frog" }) == "Today i saw a ");
}

SCENARIO("Sentence with forbidden words")
{
	REQUIRE(FilterForbiddenWords("Today i saw a frOg and Dog", set<string>{ "cat", "dog", "frog" }) == "Today i saw a  and ");
}


SCENARIO("Separator characters in a sentence")
{
	REQUIRE(FilterForbiddenWords("i watched the movie dog&cat. frog>dog", set<string>{ "cat", "dog", "frog" }) == "i watched the movie &. >");
}