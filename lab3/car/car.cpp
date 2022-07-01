#include "CCar.h"
#include "main.h"

void CommandEngineOn(std::ostream& outputStream, CCar& car)
{
	if (!car.TurnOnEngine())
	{
		outputStream << "-----------------------------------------------\n";
		outputStream << "Unable to start engine\n";
		outputStream << "-----------------------------------------------\n";
	}
}

void CommandEngineOff(std::ostream& outputStream, CCar& car)
{
	if (!car.TurnOffEngine())
	{
		outputStream << "-----------------------------------------------\n";
		outputStream << "Unable to turn off the engine\n";
		outputStream << "Need a full stop with zero speed and gear\n";
		outputStream << "-----------------------------------------------\n";
	}
}

void CommandInfo(std::ostream& outputStream, const CCar& car)
{
	outputStream << "-----------------------------------------------\n";
	outputStream << "Engine: ";
	if (car.IsTurnedOn())
	{
		outputStream << "ON\n";
	}
	else
	{
		outputStream << "OFF\n";
	}
	outputStream << "Diretion: ";
	switch (car.GetDirection())
	{
	case CCar::Direction::atRest:
		outputStream << "at rest\n";
		break;
	case CCar::Direction::back:
		outputStream << "back\n";
		break;
	case CCar::Direction::forward:
		outputStream << "forward\n";
		break;
	default:
		break;
	}
	outputStream << "Speed: " << car.GetSpeed() << "\n";
	outputStream << "Gear: " << car.GetGear() << "\n";
	outputStream << "-----------------------------------------------\n";
}

void CommandSetGear(std::ostream& outputStream, CCar& car, int const gear)
{
	if (!car.SetGear(gear))
	{
		outputStream << "-----------------------------------------------\n";
		outputStream << "Unable to change gear\n";
		if (car.GetGear() == -1 && gear > 1)
		{
			outputStream << "It is impossible to switch from reverse gear to gear more than 1\n";
		}
		if (!(gear >= CCar::minGear && gear <= CCar::maxGear))
		{
			outputStream << "Gear must be an integer between " << CCar::minGear << " and " << CCar::maxGear << "\n";
		}
		if (car.IsTurnedOn() == false)
		{
			outputStream << "Engine off\n";
		}
		if (gear < 0 && car.GetSpeed() != 0)
		{

			outputStream << "Reverse gear can only be engaged at zero speed\n";
		}
		if (gear == 1 && car.GetDirection() == CCar::Direction::back)
		{
			outputStream << "1st gear cannot be engaged from reverse\n";
		}
		if (!(car.GetSpeed() >= CCar::GetMinGearSpeed(gear) && car.GetSpeed() <= CCar::GetMaxGearSpeed(gear)))
		{
			outputStream << "In " << gear << " gear, the speed can vary from " << CCar::GetMinGearSpeed(gear)
						 << " to " << CCar::GetMaxGearSpeed(gear) << "\n";
		}
		outputStream << "-----------------------------------------------\n";
	}
}

void CoomandSetSpeed(std::ostream& outputStream, CCar& car, int const speed)
{
	if (!car.SetSpeed(speed))
	{
		outputStream << "-----------------------------------------------\n";
		outputStream << "Unable to change gear\n";
		if (car.GetGear() == 0)
		{
			outputStream << "In zero gear, you can only reduce speed\n";
			outputStream << "Current speed: " << car.GetSpeed() << "\n";
		}
		outputStream << "In " << car.GetGear() << " gear, the speed can vary from " << CCar::GetMinGearSpeed(car.GetGear())
					 << " to " << CCar::GetMaxGearSpeed(car.GetGear()) << "\n";
		outputStream << "-----------------------------------------------\n";
	}
}

void ToWorkWithCCarThroughTheStream(std::istream& inputStream, std::ostream& outputStream, CCar& car)
{
	while (!inputStream.eof())
	{
		std::string buffer;
		getline(inputStream, buffer);
		std::istringstream bufferStream(buffer);
		std::string coomand;
		if (bufferStream >> coomand)
		{
			std::transform(coomand.begin(), coomand.end(), coomand.begin(),
				[](unsigned char ch) { return static_cast<char>(::tolower(ch)); });
			if (coomand == "info")
			{
				CommandInfo(outputStream, car);
				continue;
			}
			if (coomand == "engineon")
			{
				CommandEngineOn(outputStream, car);
				continue;
			}
			if (coomand == "engineoff")
			{

				CommandEngineOff(outputStream, car);
				continue;
			}
			if (coomand == "setgear")
			{
				int gear;
				if (bufferStream >> gear)
				{
					CommandSetGear(outputStream, car, gear);
				}
				continue;
			}
			if (coomand == "setspeed")
			{
				int speed;
				if (bufferStream >> speed)
				{
					CoomandSetSpeed(outputStream, car, speed);
				}
				continue;
			}
		}
		else
		{
			continue;
		}
	}
}

// программа должна сообщать о вводе неизвестных комманд
// тест на проверку направления автомобиля
// на задней передаче на нулевой скоросте направление должно быть "на месте"
int main()
{
	CCar car;
	ToWorkWithCCarThroughTheStream(std::cin, std::cout, car);
	return 0;
}
