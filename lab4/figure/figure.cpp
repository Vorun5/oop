#include <iostream>
#include <algorithm>

#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "IShape.h"
#include "StreamControl.h"
#include "CCanvas.h"

bool ShapeAreaComp(const std::unique_ptr<IShape>& s1, const std::unique_ptr<IShape>& s2)
{
	return s1->GetArea() < s2->GetArea();
}

bool ShapePerimeterComp(const std::unique_ptr<IShape>& s1, const std::unique_ptr<IShape>& s2)
{
	return s1->GetPerimeter() < s2->GetPerimeter();
}

int main()
{	
	std::vector<std::unique_ptr<IShape>> shapes = ReadShapesFromStream(std::cin, std::cout);

	if (shapes.empty())
	{
		std::cout << "You have not enter the shapes\n";
		return 0;
	}

	auto shapeWithMaxArea = std::max_element(shapes.begin(), shapes.end(), ShapeAreaComp);
	auto shapeWithMinPerimeter = std::min_element(shapes.begin(), shapes.end(), ShapePerimeterComp);

	std::cout << "-----------------------------------------------\n";
	std::cout << "Max area\n";
	std::cout << shapeWithMaxArea->get()->ToString() << std::endl;
	std::cout << "-----------------------------------------------\n";
	std::cout << "Min perimeter\n";
	std::cout << shapeWithMinPerimeter->get()->ToString() << std::endl;
	std::cout << "-----------------------------------------------\n";
	return 0;
}
