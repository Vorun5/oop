#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../cath/catch.hpp"
#include "../lab2task1v2/lab2task1v2.h"
#include "../lab2task1v2/MultiplyByTheMinElement.cpp"

SCENARIO("Empty vector")
{
	REQUIRE(MultiplyByTheMinElement(vector<double>{}) == vector<double>{});
}

SCENARIO("Vector with 1")
{
	REQUIRE(MultiplyByTheMinElement(vector<double>{1, 2, 3}) == vector<double>{1, 2, 3});
}

SCENARIO("Whole numbers")
{
	REQUIRE(MultiplyByTheMinElement(vector<double>{ 4, 2, 3}) == vector<double>{ 8, 4, 6 });
}

SCENARIO("Negative and non-integer numbers")
{
	REQUIRE(MultiplyByTheMinElement(vector<double>{ 3, 1.2, -2, 3, 4 }) == vector<double>{ -6, -2.4, 4, -6, -8 });
}