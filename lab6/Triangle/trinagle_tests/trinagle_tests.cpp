#define CATCH_CONFIG_MAIN
#include <optional>

#include "../../../cath/catch.hpp"
#include "../trinagle/CTriangle.h"

std::optional<CTriangle> CreateTrianlge(const double& side1, const double& side2, const double& side3)
{
	try
	{
		CTriangle triangle(side1, side2, side3);
		return triangle;
	}
	catch (const std::exception& e)
	{
		return std::nullopt;
	}
}

bool IsEqual(const double& x, const double& y)
{
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

SCENARIO("With incorrect data, the triangle should not be created or modified. The sum of two sides must be greater than the third side.")
{
	// TODO: использовать catch и проверить какой тип
	auto triangle = CreateTrianlge(-10, 20, 30);
	REQUIRE(!triangle);
	triangle = CreateTrianlge(2, 3, 5);
	REQUIRE(!triangle);
	triangle = CreateTrianlge(0, 1, 2);
	REQUIRE(!triangle);
}

SCENARIO("If the triangle is built successfully, its values should be correct")
{
	GIVEN("You can create a triangle")
	{
		auto triangle = CreateTrianlge(1, 1, sqrt(2));
		REQUIRE(triangle);
		REQUIRE(IsEqual(triangle.value().GetArea(), 0.5));
		REQUIRE(IsEqual(triangle.value().GetPerimeter(), 2 + sqrt(2)));

		// TODO: больше тестов с треугольниками с целочисленными длинами сторон
		double a = sqrt(37), b = sqrt(41), c = sqrt(40);
		triangle = CreateTrianlge(a, b, c);
		REQUIRE(triangle);
		const double P = a + b + c;
		const double p = P / 2;
		const double S = sqrt(p * (p - a) * (p - b) * (p - c));
		REQUIRE(triangle.value().GetPerimeter() == P);
		REQUIRE(triangle.value().GetArea() == S);
	}

	GIVEN("You can create a constant triangle")
	{
		const CTriangle triangle(1, 1, sqrt(2));
		REQUIRE(IsEqual(triangle.GetArea(), 0.5));
		REQUIRE(IsEqual(triangle.GetPerimeter(), 2 + sqrt(2)));
	}
}