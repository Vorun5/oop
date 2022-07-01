#include "CTriangle.h"
#include "CCanvas.h"
#include "Exceptions.h"
#include <sstream>

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t fillColor, uint32_t outlineColor)
	: m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
	, m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
{
	double a = CPoint::GetDistanceBetweenTwoPoints(vertex1, vertex2);
	double b = CPoint::GetDistanceBetweenTwoPoints(vertex1, vertex3);
	double c = CPoint::GetDistanceBetweenTwoPoints(vertex2, vertex3);
	if (!((a < b + c) && (b < a + c) && (c < a + b)))
	{
		throw IncorrectData("the sum of any two sides of a triangle must be greater than the third side");
	}
}

double CTriangle::GetArea() const
{
	double a = CPoint::GetDistanceBetweenTwoPoints(m_vertex1, m_vertex2);
	double b = CPoint::GetDistanceBetweenTwoPoints(m_vertex1, m_vertex3);
	double c = CPoint::GetDistanceBetweenTwoPoints(m_vertex2, m_vertex3);
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - c) * (p - b));
	return s;
}

double CTriangle::GetPerimeter() const
{
	double a = CPoint::GetDistanceBetweenTwoPoints(m_vertex1, m_vertex2);
	double b = CPoint::GetDistanceBetweenTwoPoints(m_vertex1, m_vertex3);
	double c = CPoint::GetDistanceBetweenTwoPoints(m_vertex2, m_vertex3);
	return a + b + c;
}

std::string CTriangle::ToString() const
{

	std::stringstream areaAndPerimeter;
	areaAndPerimeter << "\nArea: " << CTriangle::GetArea() << "\nPerimeter: " << CTriangle::GetPerimeter();
	return "Shape: triangle\nFill color: #" + UInt32_tToHex(m_fillColor) + "\nOutline color: #" + UInt32_tToHex(m_outlineColor) + "\nVertix 1: " + m_vertex1.Print() + "\nVertix 2: " + m_vertex2.Print() + "\nVertix 3: " + m_vertex3.Print() + areaAndPerimeter.str();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1() const
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2() const
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3() const
{
	return m_vertex3;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points{
		m_vertex1,
		m_vertex2,
		m_vertex3,
	};
	canvas.FillPolygon(points, m_fillColor);
	canvas.DrawLine(m_vertex1, m_vertex2, m_outlineColor);
	canvas.DrawLine(m_vertex2, m_vertex3, m_outlineColor);
	canvas.DrawLine(m_vertex1, m_vertex3, m_outlineColor);
}