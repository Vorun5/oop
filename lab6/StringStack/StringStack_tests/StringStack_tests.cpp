#define CATCH_CONFIG_MAIN

#include "../../../cath/catch.hpp"
#include "../StringStack/CStringStack.h"

CStringStack StringStack123()
{
	CStringStack s;
	s.Push("1");
	s.Push("2");
	s.Push("3");
	return s;
}



SCENARIO("Check the correctness of the string stack on small values")
{
	CStringStack s;
	REQUIRE(s.Empty() == true);

	// Add items and clear
	s.Push("1");
	REQUIRE(s.Empty() == false);
	s.Push("2");
	REQUIRE(s.Empty() == false);
	s.Push("3");
	REQUIRE(s.Empty() == false);

	// Removing items
	REQUIRE(s.GetTop() == "3");
	REQUIRE(s.Empty() == false);
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "2");
	REQUIRE(s.Empty() == false);
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "1");
	REQUIRE(s.Empty() == false);
	s.Pop();
	REQUIRE(s.Empty() == true);

	// Add items and clear
	s.Push("1");
	REQUIRE(s.Empty() == false);
	s.Push("2");
	REQUIRE(s.Empty() == false);
	s.Push("3");
	REQUIRE(s.Empty() == false);
	s.Clear();
	REQUIRE(s.Empty() == true);
	REQUIRE_THROWS_AS(s.GetTop() , std::logic_error);
	REQUIRE_THROWS_AS(s.Pop(), std::logic_error);
}

SCENARIO("Check of the copy constructor")
{
	CStringStack s;
	s.Push("1");
	s.Push("2");
	s.Push("3");
	s.Push("4");
	CStringStack sCopy(s);
	REQUIRE(sCopy.Empty() == false);
	REQUIRE(sCopy.GetTop() == "4");
	sCopy.Pop();
	REQUIRE(sCopy.Empty() == false);
	REQUIRE(sCopy.GetTop() == "3");
	sCopy.Pop();
	REQUIRE(sCopy.Empty() == false);
	REQUIRE(sCopy.GetTop() == "2");
	sCopy.Pop();
	REQUIRE(sCopy.Empty() == false);
	REQUIRE(sCopy.GetTop() == "1");
	sCopy.Pop();
	REQUIRE(sCopy.Empty() == true);

	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "4");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "3");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "2");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "1");
	s.Pop();
	REQUIRE(s.Empty() == true);
}

SCENARIO("Copy the string stack into itself")
{
	CStringStack s;
	s.Push("1");
	s.Push("2");
	s = s;
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "2");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "1");
	s.Pop();
	REQUIRE(s.Empty() == true);
	s.Push("3");
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "3");
	s.Pop();
	REQUIRE(s.Empty() == true);
}

SCENARIO("Move constructor")
{
	CStringStack s = StringStack123();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "3");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "2");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "1");
	s.Pop();
	REQUIRE(s.Empty() == true);
	s.Push("3");
	REQUIRE(s.Empty() == false);
	s.Clear();
	REQUIRE(s.Empty() == true);
}

SCENARIO("Transfer operator") {
	CStringStack s;
	s.Push("0");
	s = StringStack123();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "3");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "2");
	s.Pop();
	REQUIRE(s.Empty() == false);
	REQUIRE(s.GetTop() == "1");
	s.Pop();
	REQUIRE(s.Empty() == true);
	s.Push("3");
	REQUIRE(s.Empty() == false);
	s.Clear();
	REQUIRE(s.Empty() == true);
}