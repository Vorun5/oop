#include <optional>
#include <fstream>

#include "Exceptions.h"
#include "StreamControl.h"
#include "CCanvas.h"

bool ReadDoubleFromStream(std::istream& stream, double& number)
{
	if (stream >> number)
	{
		return true;
	}

	return false;
}

bool ReadColorFromStream(std::istream& stream, std::uint32_t& color)
{
	std::string hexString;
	stream >> hexString;
	return HexToUInt32_t(hexString, color);
}

bool ReadPointFromStream(std::istream& stream, CPoint& point)
{
	double x, y;
	if (ReadDoubleFromStream(stream, x) && ReadDoubleFromStream(stream, y))
	{
		point.x = x;
		point.y = y;
		return true;
	}
	return false;
}

std::optional<std::unique_ptr<CTriangle>> ReadTriangleFromStream(std::istream& stream)
{
	CPoint vetrix1(0, 0), vetrix2(0, 0), vetrix3(0, 0);
	std::uint32_t fillColor, outlineColor;

	if (ReadPointFromStream(stream, vetrix1) && ReadPointFromStream(stream, vetrix2) && ReadPointFromStream(stream, vetrix3) && ReadColorFromStream(stream, fillColor) && ReadColorFromStream(stream, outlineColor))
	{
		return std::make_unique<CTriangle>(vetrix1, vetrix2, vetrix3, fillColor, outlineColor);
	}
	return std::nullopt;
}

std::optional<std::unique_ptr<CCircle>> ReadCircleFromStream(std::istream& stream)
{
	CPoint center(0, 0);
	double radius;
	std::uint32_t fillColor, outlineColor;
	if (ReadPointFromStream(stream, center) && ReadDoubleFromStream(stream, radius) && ReadColorFromStream(stream, fillColor) && ReadColorFromStream(stream, outlineColor))
	{
		return std::make_unique<CCircle>(center, radius, fillColor, outlineColor);
	}
	return std::nullopt;
}

std::optional<std::unique_ptr<CRectangle>> ReadRectangleFromStream(std::istream& stream)
{
	CPoint leftTop(0, 0);
	double width, heigth;
	std::uint32_t fillColor, outlineColor;
	if (ReadPointFromStream(stream, leftTop) && ReadDoubleFromStream(stream, width) && ReadDoubleFromStream(stream, heigth) && ReadColorFromStream(stream, fillColor) && ReadColorFromStream(stream, outlineColor))
	{
		return std::make_unique<CRectangle>(leftTop, width, heigth, fillColor, outlineColor);
	}
	return std::nullopt;
}

std::optional<std::unique_ptr<CLineSegment>> ReadLineSegmentFromStream(std::istream& stream)
{
	CPoint startPoint(0, 0), endPoint(0, 0);
	std::uint32_t outlineColor;
	if (ReadPointFromStream(stream, startPoint) && ReadPointFromStream(stream, endPoint) && ReadColorFromStream(stream, outlineColor))
	{
		return std::make_unique<CLineSegment>(startPoint, endPoint, outlineColor);
	}
	return std::nullopt;
}

// TODO: выбрать один способ обработки ошибок
// TODO: выбрать название, полностью описывающее метод
std::vector<std::unique_ptr<IShape>> ReadShapesFromStream(std::istream& stream, std::ostream& errorStream)
{
	std::vector<std::unique_ptr<IShape>> shapes;
	CCanvas canvas(1280, 720);
	while (!stream.eof())
	{

		std::string stringWithShape;

		std::getline(stream, stringWithShape);

		std::istringstream streamWithCommand(stringWithShape);

		std::string commandType;

		streamWithCommand >> commandType;

		if (commandType == "rectangle")
		{
			try
			{
				if (auto rectangle = ReadRectangleFromStream(streamWithCommand))
				{
					shapes.push_back(std::move(rectangle.value()));
				}
				else
				{
					errorStream << "Shape input error\n";
				}
			}
			catch (const IncorrectData& e)
			{
				errorStream << "Incorrect data: " << e.what() << std::endl;
			}
			continue;
		}

		if (commandType == "triangle")
		{
			try
			{
				if (auto triangle = ReadTriangleFromStream(streamWithCommand))
				{
					shapes.push_back(std::move(triangle.value()));
				}
				else
				{
					errorStream << "Shape input error\n";
				}
			}
			catch (const IncorrectData& e)
			{
				errorStream << "Incorrect data: " << e.what() << std::endl;
			}
			continue;
		}

		if (commandType == "circle")
		{
			try
			{
				if (auto circle = ReadCircleFromStream(streamWithCommand))
				{
					shapes.push_back(std::move(circle.value()));
				}
				else
				{
					errorStream << "Shape input error\n";
				}
			}
			catch (const IncorrectData& e)
			{
				errorStream << "Incorrect data: " << e.what() << std::endl;
			}
			continue;
		}

		if (commandType == "linesegment")
		{
			try
			{
				if (auto lineSegment = ReadLineSegmentFromStream(streamWithCommand))
				{
					shapes.push_back(std::move(lineSegment.value()));
				}
				else
				{
					errorStream << "Shape input error\n";
				}
			}
			catch (const IncorrectData& e)
			{
				errorStream << "Incorrect data: " << e.what() << std::endl;
			}
			continue;
		}
		
		if (commandType == "file")
		{
			std::string filePath;
			streamWithCommand >> filePath;
			std::ifstream file(filePath);
			if (!file)
			{
				errorStream << "File not found\n";
				continue;
			}
			shapes = ReadShapesFromStream(file, errorStream);
			continue;
		}

		if (commandType == "show")
		{
			canvas.Clear();
			
			for (auto& shape: shapes)
			{
				shape->Draw(canvas);
			}
			
			canvas.Show();
			continue;
		}

		if (commandType == "clear")
		{
			shapes.clear();
			continue;
		}

		if (commandType == "...")
		{
			break;
		}

		errorStream << "Unknown command\n";
	}
	return shapes;
}
