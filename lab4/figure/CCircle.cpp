#include "CCircle.h"
#include "ColorConverter.h"
#include "Exceptions.h"
#include <corecrt_math_defines.h>
#include <sstream>

CCircle::CCircle(CPoint center, double radius, uint32_t fillColor, uint32_t outlineColor)
	: m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
	, m_center(center)
	, m_radius(radius)
{
	if (!(radius > 0))
	{
		throw IncorrectData("the radius of the circle must be greater than zero");
	}
}

// ISolidShape
double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, 2);
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString() const
{

	std::stringstream areaAndPerimeter;
	areaAndPerimeter << "\nArea: " << CCircle::GetArea() << "\nPerimeter: " << CCircle::GetPerimeter();
	std::stringstream radius;
	radius << "\nRadius: " << m_radius;
	return "Shape: circle\nFill color: #" + UInt32_tToHex(m_fillColor) + "\nOutline color: #" + UInt32_tToHex(m_outlineColor) + "\nCenter: " + m_center.Print() + radius.str() + areaAndPerimeter.str();
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

// CCircle

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.DrawCirlce(m_center, m_radius, m_outlineColor);
	canvas.FillCirlce(m_center, m_radius, m_fillColor);
}
