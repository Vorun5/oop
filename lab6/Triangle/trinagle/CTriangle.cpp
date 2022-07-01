#include "CTriangle.h"
#include <stdexcept>

CTriangle::CTriangle(double side1, double side2, double side3)
	: m_side1(side1)
	, m_side2(side2)
	, m_side3(side3)
{

	if (side1 <= 0 || side2 <= 0 || side3 <= 0)
	{
		throw std::invalid_argument("Any side must be greater than zero");
	}

	if (!((side1 < side2 + side3) && (side2 < side1 + side3) && (side3 < side1 + side2)))
	{
		throw std::domain_error("The sum of any two sides must be greater than the third");
	}

}

double CTriangle::GetSide1() const
{
	return m_side1;
}

double CTriangle::GetSide2() const
{
	return m_side2;
}

double CTriangle::GetSide3() const
{
	return m_side3;
}

double CTriangle::GetArea() const
{
	double p = (m_side1 + m_side2 + m_side3) / 2;
	double s = sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
	return s;
}

double CTriangle::GetPerimeter() const
{
	return m_side1 + m_side2 + m_side3;
}