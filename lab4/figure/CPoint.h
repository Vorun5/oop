#pragma once
#include <string>

class CPoint {
public:
	CPoint(double x, double y);
	double x;
	double y;
	std::string Print() const;
	static double GetDistanceBetweenTwoPoints(CPoint p1, CPoint p2);
};
