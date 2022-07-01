#include <sstream>
#include "CPoint.h"

CPoint::CPoint(double x, double y)
	: x(x)
	, y(y)
{}

std::string CPoint::Print() const
{
	std::stringstream stream;
	stream << "(" << x << ", " << y << ")";
	return stream.str();
}
// TODO: GetDistance
double CPoint::GetDistanceBetweenTwoPoints(CPoint p1, CPoint p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}