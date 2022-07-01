#include "CTriangle.h"
#include <iostream>
#include <optional>
#include <sstream>
#include <string>

std::optional<CTriangle> ReadTrinagleFromString(const std::string& str)
{
	double side1 = 0, side2 = 0, side3 = 0;
	std::istringstream stream(str);
	if (stream >> side1 && stream >> side2 && stream >> side3)
	{
		CTriangle triangle(side1, side2, side3);
		return triangle;
	}
	return std::nullopt;
}

// TODO: использовать один стиль оброботки ошибок
int main()
{
	while (!std::cin.eof())
	{
		std::string str;
		std::getline(std::cin, str);
		try
		{
			auto trinagle = ReadTrinagleFromString(str);
			if (trinagle)
			{
				std::cout << "Area: " << trinagle.value().GetArea() << std::endl;
				std::cout << "Perimeter: " << trinagle.value().GetPerimeter() << std::endl;
			}
			else
			{
				std::cout << "It is not triangle\n";
			}
		}
		catch (const std::invalid_argument& e)
		{
			std::cout << "Invalid argument: " << e.what() << std::endl;
		}
		catch (const std::domain_error& e)
		{
			std::cout << "Domain error: " << e.what() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	return 0;
}