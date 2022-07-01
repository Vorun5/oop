#include <sstream>
#include <string>

#include "CLineSegment.h"
#include "ColorConverter.h"
#include "Exceptions.h"

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
	if (startPoint.x == endPoint.x && startPoint.y == endPoint.y)
	{
		throw IncorrectData("the start and end points of the line segment must be different");
	}
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return CPoint::GetDistanceBetweenTwoPoints(m_startPoint, m_endPoint);
}

std::string CLineSegment::ToString() const
{
	std::stringstream areaAndPerimeter;
	areaAndPerimeter << "\nArea: " << CLineSegment::GetArea() << "\nPerimeter: " << CLineSegment::GetPerimeter();
	return "Shape: line segment\nOutline color: #" + UInt32_tToHex(m_outlineColor) + "\nStart point: " + m_startPoint.Print() + "\nEnd point: " + m_endPoint.Print() + areaAndPerimeter.str();
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{ 
	return m_endPoint;
}

void CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.DrawLine(m_startPoint, m_endPoint, m_outlineColor);
}
