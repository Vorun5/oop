#define CATCH_CONFIG_MAIN

#include "../../../cath/catch.hpp"
#include "../FindMaxEx/FindMaxEx.h"
#include "../FindMaxEx/Athlete.h"

const std::vector<Athlete> athletes = { Athlete("Firdavsi Nurov", 70, 183), Athlete("Kot Boris", 70.5, 25), Athlete("Blue Frog", 0.3, 190) };

SCENARIO("Empty array")
{
	std::vector<Athlete> emptyArr;
	Athlete a("", 0.0, 0);
	REQUIRE(emptyArr.empty());
	REQUIRE(!FindMaxEx(emptyArr, a, WeightComp));
	REQUIRE(!FindMaxEx(emptyArr, a, HeightComp));
	REQUIRE(!FindMaxEx(emptyArr, a, NameComp));
}

SCENARIO("Find max name (string)")
{
	Athlete a("", 0.0, 0);
	REQUIRE(FindMaxEx(athletes, a, NameComp));
	REQUIRE(a.name == "Kot Boris");
}

SCENARIO("Find max weight (dobule)")
{
	Athlete a("", 0.0, 0);
	REQUIRE(FindMaxEx(athletes, a, WeightComp));
	REQUIRE(a.weight == 70.5);
}

SCENARIO("Find max height (int)")
{
	Athlete a("", 0.0, 0);
	REQUIRE(FindMaxEx(athletes, a, HeightComp));
	REQUIRE(a.height == 190);
}