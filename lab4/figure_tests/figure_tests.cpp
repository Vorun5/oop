#define CATCH_CONFIG_MAIN
#include <iostream>
#include <optional>

#include "../../cath/catch.hpp"
#include "../figure/CCircle.h"
#include "../figure/CLineSegment.h"
#include "../figure/CPoint.h"
#include "../figure/CRectangle.h"
#include "../figure/CTriangle.h"
#include "../figure/Exceptions.h"
#include <corecrt_math_defines.h>

using namespace std;
// TODO: функции с большой буквы

bool isEqual(double x, double y)
{
	return std::fabs(x - y) < std::numeric_limits<double>::epsilon();
}

// TODO: константы названы не по соглашению
const uint32_t black = 0;
// TODO: опечатка
const double startPerimentr = 2 + sqrt(2);

std::optional<CTriangle> CreateTrianlge(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t fillColor, uint32_t outlineColor)
{
	try
	{
		CTriangle triangle(vertex1, vertex2, vertex3, fillColor, outlineColor);
		return triangle;
	}
	catch (const IncorrectData& e)
	{
		return std::nullopt;
	}
}

std::optional<CRectangle> CreateRectangle(CPoint leftTop, double width, double heigth, uint32_t fillColor, uint32_t outlineColor)
{
	try
	{
		CRectangle rectangle(leftTop, width, heigth, fillColor, outlineColor);
		return rectangle;
	}
	catch (const IncorrectData& e)
	{
		return std::nullopt;
	}
}

std::optional<CCircle> CreateCircle(CPoint center, double radius, uint32_t fillColor, uint32_t outlineColor)
{
	try
	{
		CCircle cirlce(center, radius, fillColor, outlineColor);
		return cirlce;
	}
	catch (const IncorrectData& e)
	{
		return std::nullopt;
	}
}

std::optional<CLineSegment> CreateLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
{
	try
	{
		CLineSegment lineSegment(startPoint, endPoint, outlineColor);
		return lineSegment;
	}
	catch (const IncorrectData& e)
	{
		return std::nullopt;
	}
}

// triangle

SCENARIO("With incorrect data, the triangle should not be created or modified. The sum of two sides must be greater than the third side.")
{
	auto triangle = CreateTrianlge(CPoint(0, 0), CPoint(0, 2), CPoint(0, 5), 0, 0);
	REQUIRE(!triangle);
	triangle = CreateTrianlge(CPoint(32, 32), CPoint(-12, 32), CPoint(32, 32), 123, 1232);
	REQUIRE(!triangle);
	triangle = CreateTrianlge(CPoint(0, 0), CPoint(0, 0), CPoint(0, 0), 100, 100);
	REQUIRE(!triangle);
}

SCENARIO("If the triangle is built successfully, its values should be correct")
{
	GIVEN("You can create a triangle")
	{
		auto triangle = CreateTrianlge(CPoint(0, 0), CPoint(1, 0), CPoint(0, 1), black, black);
		REQUIRE(triangle);
		REQUIRE(isEqual(triangle.value().GetArea(), 0.5));
		REQUIRE(isEqual(triangle.value().GetPerimeter(), startPerimentr));
		REQUIRE(triangle.value().GetFillColor() == black);
		REQUIRE(triangle.value().GetOutlineColor() == black);
		REQUIRE(triangle.value().GetVertex1().x == 0);
		REQUIRE(triangle.value().GetVertex1().y == 0);
		REQUIRE(triangle.value().GetVertex2().x == 1);
		REQUIRE(triangle.value().GetVertex2().y == 0);
		REQUIRE(triangle.value().GetVertex3().x == 0);
		REQUIRE(triangle.value().GetVertex3().y == 1);

		triangle = CreateTrianlge(CPoint(2, 3), CPoint(3, -3), CPoint(-3, -1), 100, 200);
		REQUIRE(triangle);
		REQUIRE(triangle.value().GetVertex1().x == 2);
		REQUIRE(triangle.value().GetVertex1().y == 3);
		REQUIRE(triangle.value().GetVertex2().x == 3);
		REQUIRE(triangle.value().GetVertex2().y == -3);
		REQUIRE(triangle.value().GetVertex3().x == -3);
		REQUIRE(triangle.value().GetVertex3().y == -1);
		REQUIRE(triangle.value().GetFillColor() == 100);
		REQUIRE(triangle.value().GetOutlineColor() == 200);
		const double a = sqrt(37);
		const double b = sqrt(41);
		const double c = sqrt(40);
		const double P = a + b + c;
		const double p = P / 2;
		const double S = sqrt(p * (p - a) * (p - b) * (p - c));
		REQUIRE(triangle.value().GetPerimeter() == P);
		REQUIRE(triangle.value().GetArea() == S);
	}

	GIVEN("You can create a constant triangle")
	{
		const CTriangle triangle1(CPoint(0, 0), CPoint(1, 0), CPoint(0, 1), black, black);
		REQUIRE(isEqual(triangle1.GetArea(), 0.5));
		REQUIRE(isEqual(triangle1.GetPerimeter(), startPerimentr));
		REQUIRE(triangle1.GetFillColor() == black);
		REQUIRE(triangle1.GetOutlineColor() == black);
		REQUIRE(triangle1.GetVertex1().x == 0);
		REQUIRE(triangle1.GetVertex1().y == 0);
		REQUIRE(triangle1.GetVertex2().x == 1);
		REQUIRE(triangle1.GetVertex2().y == 0);
		REQUIRE(triangle1.GetVertex3().x == 0);
		REQUIRE(triangle1.GetVertex3().y == 1);

		const CTriangle triangle2(CPoint(2, 3), CPoint(3, -3), CPoint(-3, -1), 100, 200);
		REQUIRE(triangle2.GetVertex1().x == 2);
		REQUIRE(triangle2.GetVertex1().y == 3);
		REQUIRE(triangle2.GetVertex2().x == 3);
		REQUIRE(triangle2.GetVertex2().y == -3);
		REQUIRE(triangle2.GetVertex3().x == -3);
		REQUIRE(triangle2.GetVertex3().y == -1);
		REQUIRE(triangle2.GetFillColor() == 100);
		REQUIRE(triangle2.GetOutlineColor() == 200);
		const double a = sqrt(37);
		const double b = sqrt(41);
		const double c = sqrt(40);
		const double P = a + b + c;
		const double p = P / 2;
		const double S = sqrt(p * (p - a) * (p - b) * (p - c));
		REQUIRE(triangle2.GetPerimeter() == P);
		REQUIRE(triangle2.GetArea() == S);
	}
}

// rectangle

SCENARIO("With incorrect data, the rectangle should not be created or modified. The width and height of the rectangle must be greater than zero.")
{
	auto rectangle = CreateRectangle(CPoint(0, 0), -10, 20, black, black);
	REQUIRE(!rectangle);
	rectangle = CreateRectangle(CPoint(0, 0), 10, -20, black, black);
	REQUIRE(!rectangle);
	rectangle = CreateRectangle(CPoint(0, 0), 0, 10, black, black);
	REQUIRE(!rectangle);
	rectangle = CreateRectangle(CPoint(0, 0), 10, 0, black, black);
	REQUIRE(!rectangle);
}

SCENARIO("If the rectangle is built successfully, its values should be correct")
{
	GIVEN("You can create a rectangle")
	{
		auto rectangle = CreateRectangle(CPoint(0, 0), 10, 20, black, black);
		REQUIRE(rectangle);
		REQUIRE(isEqual(rectangle.value().GetArea(), 200));
		REQUIRE(isEqual(rectangle.value().GetWidth(), 10));
		REQUIRE(isEqual(rectangle.value().GetHeight(), 20));
		REQUIRE(isEqual(rectangle.value().GetPerimeter(), 60));
		REQUIRE(rectangle.value().GetFillColor() == black);
		REQUIRE(rectangle.value().GetOutlineColor() == black);
		REQUIRE(isEqual(rectangle.value().GetLeftTop().x, 0));
		REQUIRE(isEqual(rectangle.value().GetLeftTop().y, 0));
	}

	GIVEN("You can create a constant rectangle")
	{
		const CRectangle rectangle(CPoint(0, 0), 10, 20, black, black);
		REQUIRE(isEqual(rectangle.GetArea(), 200));
		REQUIRE(isEqual(rectangle.GetWidth(), 10));
		REQUIRE(isEqual(rectangle.GetHeight(), 20));
		REQUIRE(isEqual(rectangle.GetPerimeter(), 60));
		REQUIRE(rectangle.GetFillColor() == black);
		REQUIRE(rectangle.GetOutlineColor() == black);
		REQUIRE(isEqual(rectangle.GetLeftTop().x, 0));
		REQUIRE(isEqual(rectangle.GetLeftTop().y, 0));
	}
}

// circle

SCENARIO("With incorrect data, the circle should not be created or modified. Circle radius must be greater than zero.")
{
	auto circle = CreateCircle(CPoint(0, 0), -10, black, black);
	REQUIRE(!circle);
	circle = CreateCircle(CPoint(0, 0), 0, black, black);
	REQUIRE(!circle);
}

SCENARIO("If the circle is built successfully, its values should be correct")
{
	GIVEN("You can create a circle")
	{
		auto circle = CreateCircle(CPoint(0, 0), 1, black, black);
		REQUIRE(circle);
		REQUIRE(isEqual(circle.value().GetArea(), M_PI));
		REQUIRE(isEqual(circle.value().GetPerimeter(), (2 * M_PI)));
		REQUIRE(isEqual(circle.value().GetRadius(), 1));
		REQUIRE(isEqual(circle.value().GetCenter().x, 0));
		REQUIRE(isEqual(circle.value().GetCenter().y, 0));
		REQUIRE(circle.value().GetFillColor() == 0);
		REQUIRE(circle.value().GetOutlineColor() == 0);
	}

	GIVEN("You can create a constant circle")
	{
		const CCircle circle(CPoint(0, 0), 1, black, black);
		REQUIRE(isEqual(circle.GetArea(), M_PI));
		REQUIRE(isEqual(circle.GetPerimeter(), (2 * M_PI)));
		REQUIRE(isEqual(circle.GetRadius(), 1));
		REQUIRE(isEqual(circle.GetCenter().x, 0));
		REQUIRE(isEqual(circle.GetCenter().y, 0));
		REQUIRE(circle.GetFillColor() == 0);
		REQUIRE(circle.GetOutlineColor() == 0);
	}
}

// line segment

SCENARIO("With incorrect data, the line segment should not be created or modified. The start and end points of a line segment must not be in the same place.")
{
	auto lineSegment = CreateLineSegment(CPoint(0, 0), CPoint(0, 0), black);
	REQUIRE(!lineSegment);
	lineSegment = CreateLineSegment(CPoint(10, 10), CPoint(10, 10), black);
	REQUIRE(!lineSegment);
	lineSegment = CreateLineSegment(CPoint(-10, -10), CPoint(-10, -10), black);
	REQUIRE(!lineSegment);
}

SCENARIO("If the line segment is built successfully, its values should be correct")
{
	GIVEN("You can create a line segment")
	{
		auto lineSegment = CreateLineSegment(CPoint(0, 0), CPoint(0, 1), black);
		REQUIRE(lineSegment);
		REQUIRE(lineSegment.value().GetStartPoint().y == 0);
		REQUIRE(lineSegment.value().GetStartPoint().x == 0);
		REQUIRE(lineSegment.value().GetEndPoint().y == 1);
		REQUIRE(lineSegment.value().GetEndPoint().x == 0);
		REQUIRE(lineSegment.value().GetOutlineColor() == black);
		REQUIRE(lineSegment.value().GetArea() == 0);
		REQUIRE(lineSegment.value().GetPerimeter() == 1);
	}

	GIVEN("You can create a constant line segment")
	{
		const CLineSegment lineSegment(CPoint(0, 0), CPoint(0, 1), black);
		REQUIRE(lineSegment.GetStartPoint().y == 0);
		REQUIRE(lineSegment.GetStartPoint().x == 0);
		REQUIRE(lineSegment.GetEndPoint().y == 1);
		REQUIRE(lineSegment.GetEndPoint().x == 0);
		REQUIRE(lineSegment.GetOutlineColor() == black);
		REQUIRE(lineSegment.GetArea() == 0);
		REQUIRE(lineSegment.GetPerimeter() == 1);
	}
}