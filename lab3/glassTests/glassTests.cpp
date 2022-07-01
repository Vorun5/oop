#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../cath/catch.hpp"
#include "../glass/main.h"
#include "../glass/CGlass.h"

using namespace std;

SCENARIO("The tests")
{
	CGlass validGlass(10);



	// пытаемся создать скакан отрицательной вместимости
	CGlass invalidGlass(-10);

	REQUIRE(validGlass.GetCapacity() == 10);
	REQUIRE(validGlass.GetWaterAmount() == 0);
	REQUIRE(invalidGlass.GetCapacity() == 0);
	REQUIRE(invalidGlass.GetWaterAmount() == 0);
}