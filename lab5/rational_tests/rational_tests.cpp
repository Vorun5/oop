#define CATCH_CONFIG_MAIN
#include <fstream>
#include <iostream>

#include "../../cath/catch.hpp"
#include "../rational/CRational.h"
#include <corecrt_math_defines.h>

using namespace std;

SCENARIO("The rational number must be created valid its methods must work correctly")
{

	GIVEN("The constructor without value should create numerator = 0 and denominator = 1")
	{
		REQUIRE(2 == 2);

		CRational rational;
		REQUIRE(rational.GetDenominator() == 1);
		REQUIRE(rational.GetNumerator() == 0);
		REQUIRE(rational.ToDouble() == 0.0);
	}

	GIVEN("The constructor with one value should create numerator = value and denominator = 1")
	{
		CRational rational(41);
		REQUIRE(rational.GetDenominator() == 1);
		REQUIRE(rational.GetNumerator() == 41);
		REQUIRE(rational.ToDouble() == 41.0);
	}

	GIVEN("The constructor with two value should create numerator = numerator and denominator = denominator")
	{
		CRational rational(42, 20);
		REQUIRE(rational.GetDenominator() == 10);
		REQUIRE(rational.GetNumerator() == 21);
		REQUIRE(rational.ToDouble() == 21.0 / 10.0);
	}

	GIVEN("If the denominator is 0, then a logical exception must be thrown")
	{
		try
		{
			CRational rational(241, 0);
			REQUIRE(false == true);
		}
		catch (const std::invalid_argument& e)
		{
			// You cannot divide by zero
		}
	}

	GIVEN("The rational number must be normalized when creating")
	{
		CRational rational(6, 8);
		REQUIRE(rational.GetDenominator() == 4);
		REQUIRE(rational.GetNumerator() == 3);
		
		REQUIRE(rational.ToDouble() == 3.0 / 4.0);

		CRational rational2(8, -6);
		REQUIRE(rational2.GetDenominator() == 3);
		REQUIRE(rational2.GetNumerator() == -4);
		REQUIRE(rational2.ToDouble() == -4.0 / 3.0);
	}
}

SCENARIO("Calculation operators for  rational number operators must work correctly")
{

	GIVEN("Unary minus")
	{
		CRational rational(6, 8);
		rational = -rational;
		REQUIRE(rational.GetDenominator() == 4);
		REQUIRE(rational.GetNumerator() == -3);
		REQUIRE(rational.ToDouble() == -3.0 / 4.0);

		CRational rational2(8, -6);
		rational2 = -rational2;
		REQUIRE(rational2.GetDenominator() == 3);
		REQUIRE(rational2.GetNumerator() == 4);
		REQUIRE(rational2.ToDouble() == 4.0 / 3.0);
	}

	GIVEN("Unary plus")
	{
		CRational rational(1, 8);
		rational = +rational;
		REQUIRE(rational.GetDenominator() == 8);
		REQUIRE(rational.GetNumerator() == 1);
		REQUIRE(rational.ToDouble() == 1.0 / 8.0);
	}

	GIVEN("Addition operator")
	{
		CRational rational(1, 2);
		rational += CRational(1, 6);
		REQUIRE(rational.GetNumerator() == 2);
		REQUIRE(rational.GetDenominator() == 3);
		REQUIRE(rational.ToDouble() == 2.0 / 3.0);

		CRational rational2;
		rational2 = CRational(1, 2) + 2;
		REQUIRE(rational2.GetNumerator() == 5);
		REQUIRE(rational2.GetDenominator() == 2);
		REQUIRE(rational2.ToDouble() == 5.0 / 2.0);
	}

	GIVEN("Subtraction operator")
	{
		CRational rational(1, 2);
		rational -= CRational(1, 6);
		REQUIRE(rational.GetDenominator() == 3);
		REQUIRE(rational.GetNumerator() == 1);
		REQUIRE(rational.ToDouble() == 1.0 / 3.0);

		CRational rational2;
		rational2 = CRational(1, 2) - 1;
		REQUIRE(rational2.GetNumerator() == -1);
		REQUIRE(rational2.GetDenominator() == 2);
		REQUIRE(rational2.ToDouble() == -1.0 / 2.0);
	}

	GIVEN("Division operator")
	{
		CRational rational(1, 2);
		rational /= CRational(2, 3);
		REQUIRE(rational.GetNumerator() == 3);
		REQUIRE(rational.GetDenominator() == 4);
		REQUIRE(rational.ToDouble() == 3.0 / 4.0);

		CRational rational2;
		rational2 = CRational(1, 2) / 5;
		REQUIRE(rational2.GetNumerator() == 1);
		REQUIRE(rational2.GetDenominator() == 10);
		REQUIRE(rational2.ToDouble() == 1.0 / 10.0);

		GIVEN("You cannot divide by zero")
		{
			CRational rational3;
			try
			{
				rational3 = CRational(1, 2) / 0;
				REQUIRE(true == false);
			}
			catch (const std::invalid_argument& e)
			{
				// You cannot divide by zero
			}

			try
			{
				rational3 /= 0;
				REQUIRE(true == false);
			}
			catch (const std::exception& e)
			{
				// You cannot divide by zero
			}
		}
	}

	GIVEN("Multiplication operator")
	{
		CRational rational(1, 2);
		rational *= CRational(2, 3);
		REQUIRE(rational.GetNumerator() == 1);
		REQUIRE(rational.GetDenominator() == 3);
		REQUIRE(rational.ToDouble() == 1.0 / 3.0);

		CRational rational2;
		rational2 = CRational(1, 2) / 3;
		REQUIRE(rational2.GetNumerator() == 1);
		REQUIRE(rational2.GetDenominator() == 6);
		REQUIRE(rational2.ToDouble() == 1.0 / 6.0);

		CRational rational3;
		rational3 = CRational(1, 2) * 0;
		REQUIRE(rational3.GetNumerator() == 0);
		REQUIRE(rational3.GetDenominator() == 1);
		REQUIRE(rational3.ToDouble() == 0.0 / 1.0);
	}
}

SCENARIO("Operators comparing rational numbers must work correctly")
{

	GIVEN("Equality and Non-Equality Operators")
	{
		REQUIRE(CRational(1, 2) == CRational(1, 2));
		REQUIRE(!(CRational(1, 2) == 7));
		REQUIRE(CRational(4, 2) == 2);
		REQUIRE(CRational(4, 2) != 3);
		REQUIRE(CRational(-7, 2) == CRational(-7, 2));
		REQUIRE(!(CRational(-5, 2) == CRational(-7, 2)));
		REQUIRE(CRational(-7, 2) != CRational(1, 2));
		REQUIRE(!(CRational(1, 2) != CRational(1, 2)));
	}

	GIVEN("Comparison operators")
	{
		REQUIRE(CRational(4, 2) >= 2);
		REQUIRE(CRational(1, 2) >= CRational(1, 3));
		REQUIRE(!(CRational(1, 2) <= CRational(1, 3)));
		REQUIRE(CRational(3, 1) > 2);
		REQUIRE(!(CRational(3, 1) > 5));
		REQUIRE(!(CRational(1, 2) < CRational(1, 3)));
		REQUIRE(CRational(1, 2) < 7);
		REQUIRE(3 <= CRational(7, 2));
		REQUIRE(!(3 >= CRational(8, 2)));
	}
}

SCENARIO("Stream input and output operators must correctly read and output rational numbers")
{

	GIVEN("Stream reading")
	{
		std::stringstream stream("-1/10 kat");
		CRational rational;
		REQUIRE(stream >> rational);
		REQUIRE(rational.GetNumerator() == -1);
		REQUIRE(rational.GetDenominator() == 10);
		REQUIRE(rational.ToDouble() == -1.0 / 10.0);
		REQUIRE(!(stream >> rational));
	}

	GIVEN("Output to stream")
	{
		std::stringstream stream("");
		CRational rational(7, 3);
		REQUIRE(stream << rational);
		REQUIRE(stream.str() == "7/3");
	}
}

SCENARIO("Check ToCompoundFraction for correct operation")
{
	CRational rational(-9, 4);
	REQUIRE(rational.ToCompoundFraction().first == -2);
	REQUIRE(rational.ToCompoundFraction().second == CRational(-1, 4));

	CRational rational2(1, 2);
	REQUIRE(rational2.ToCompoundFraction().first == 0);
	REQUIRE(rational2.ToCompoundFraction().second == CRational(1, 2));

	CRational rational3(7, 2);
	REQUIRE(rational3.ToCompoundFraction().first == 3);
	REQUIRE(rational3.ToCompoundFraction().second == CRational(1, 2));
}


SCENARIO("Multiplication operator overflow") {
	CRational rational(100, INT_MAX);
	rational = rational * rational;
	REQUIRE(rational.GetNumerator() == 10000);
	REQUIRE(rational.GetDenominator() == INT_MAX);
	REQUIRE(rational.ToDouble() == 10000.0 / static_cast<double>(INT_MAX));
}