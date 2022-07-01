#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../cath/catch.hpp"
#include "../car/CCar.h"
#include "../car/main.h"

using namespace std;

SCENARIO("Checking the condition of a new car")
{
	CCar newCar;
	REQUIRE(newCar.GetSpeed() == 0);
	REQUIRE(newCar.GetGear() == 0);
	REQUIRE(newCar.GetDirection() == CCar::Direction::atRest);
	REQUIRE(newCar.IsTurnedOn() == false);
}

SCENARIO("Engine on and off test")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.IsTurnedOn());
	REQUIRE(true == car.TurnOffEngine());
	REQUIRE(false == car.IsTurnedOn());
}

SCENARIO("Start the engine and change gear")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.IsTurnedOn());
	REQUIRE(true == car.SetGear(1));
	REQUIRE(true == car.SetGear(0));
	REQUIRE(true == car.SetGear(-1));
	REQUIRE(false == car.SetGear(2));
	REQUIRE(false == car.SetGear(3));
	REQUIRE(false == car.SetGear(4));
	REQUIRE(false == car.SetGear(5));
}

SCENARIO("Checking the ways of changing the state of the engine, shifting gears and changing speed")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(car.IsTurnedOn() == true);
	REQUIRE(true == car.SetGear(1));
	REQUIRE(car.GetGear() == 1);
	REQUIRE(true == car.SetSpeed(25));
	REQUIRE(car.GetSpeed() == 25);
	REQUIRE(car.GetSpeed() == 25);
}

SCENARIO("Change speed and gear when the car engine is off")
{
	CCar car;
	REQUIRE(true == car.TurnOffEngine());
	REQUIRE(false == car.IsTurnedOn());
	REQUIRE(false == car.SetGear(1));
	REQUIRE(true == car.SetGear(0));
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(false == car.SetSpeed(20));
}

SCENARIO("Shifting from reverse to forward only at zero speed")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.SetGear(-1));
	REQUIRE(true == car.SetSpeed(20));
	REQUIRE(false == car.SetGear(2));
	REQUIRE(false == car.SetGear(5));
	REQUIRE(CCar::Direction::back == car.GetDirection());
	REQUIRE(false == car.SetGear(1));
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(true == car.SetGear(1));
}

SCENARIO("Checking the first gear from neutral at non-zero speed")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.SetGear(-1));
	REQUIRE(true == car.SetSpeed(20));
	REQUIRE(true == car.SetGear(0));
	REQUIRE(false == car.SetGear(1));
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(true == car.SetGear(0));
}

SCENARIO("In neutral gear, you can only reduce the speed modulo")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.SetGear(-1));
	REQUIRE(true == car.SetSpeed(10));
	REQUIRE(true == car.SetGear(0));
	REQUIRE(false == car.SetSpeed(15));
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(true == car.SetGear(1));
	REQUIRE(true == car.SetSpeed(20));
	REQUIRE(true == car.SetGear(0));
	REQUIRE(false == car.SetSpeed(25));
	REQUIRE(true == car.SetSpeed(15));
}

SCENARIO("Check engine stop at different speeds and gears")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.SetGear(-1));
	REQUIRE(false == car.TurnOffEngine());
	REQUIRE(true == car.SetSpeed(10));
	REQUIRE(false == car.TurnOffEngine());
	REQUIRE(true == car.SetGear(0));
	REQUIRE(false == car.TurnOffEngine());
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(true == car.TurnOffEngine());
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.SetGear(1));
	REQUIRE(false == car.TurnOffEngine());
	REQUIRE(true == car.SetSpeed(20));
	REQUIRE(false == car.TurnOffEngine());
	REQUIRE(true == car.SetGear(0));
	REQUIRE(false == car.TurnOffEngine());
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(true == car.TurnOffEngine());
	REQUIRE(false == car.IsTurnedOn());
}

SCENARIO("Test for maximum speed and braking and checking of class constant methods")
{
	CCar car;
	REQUIRE(true == car.TurnOnEngine());
	REQUIRE(true == car.IsTurnedOn());
	REQUIRE(true == car.SetGear(1));
	REQUIRE(1 == car.GetGear());
	REQUIRE(true == car.SetSpeed(30));
	REQUIRE(30 == car.GetSpeed());
	REQUIRE(false == car.SetSpeed(40));	
	REQUIRE(40 != car.GetSpeed());
	REQUIRE(false == car.SetGear(4));
	REQUIRE(4 != car.GetGear());
	REQUIRE(true == car.SetGear(2));
	REQUIRE(2 == car.GetGear());
	REQUIRE(true == car.SetSpeed(50));
	REQUIRE(50 == car.GetSpeed());
	REQUIRE(true == car.SetGear(3));
	REQUIRE(3 == car.GetGear());
	REQUIRE(true == car.SetSpeed(60));
	REQUIRE(60 == car.GetSpeed());
	REQUIRE(true == car.SetGear(4));
	REQUIRE(4 == car.GetGear());
	REQUIRE(true == car.SetSpeed(90));
	REQUIRE(90 == car.GetSpeed());
	REQUIRE(true == car.SetGear(5));
	REQUIRE(5 == car.GetGear());
	REQUIRE(true == car.SetSpeed(150));
	REQUIRE(150 == car.GetSpeed());
	REQUIRE(false == car.SetSpeed(200));
	REQUIRE(200 != car.GetSpeed());
	REQUIRE(false == car.SetGear(-1));
	REQUIRE(-1 != car.GetGear());
	REQUIRE(true == car.SetSpeed(50));
	REQUIRE(50 == car.GetSpeed());
	REQUIRE(true == car.SetGear(3));
	REQUIRE(3 == car.GetGear());
	REQUIRE(true == car.SetSpeed(30));
	REQUIRE(30 == car.GetSpeed());
	REQUIRE(true == car.SetGear(1));
	REQUIRE(1 == car.GetGear());
	REQUIRE(true == car.SetSpeed(0));
	REQUIRE(0 == car.GetSpeed());
	REQUIRE(true == car.SetGear(0));
	REQUIRE(0 == car.GetGear());
	REQUIRE(true == car.TurnOffEngine());
	REQUIRE(false == car.IsTurnedOn());
}