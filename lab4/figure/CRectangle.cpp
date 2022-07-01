#include <sstream>
#include <string>

#include "CRectangle.h"
#include "ColorConverter.h"
#include "Exceptions.h"
#include "CCanvas.h"

CRectangle::CRectangle(CPoint leftTop, double width, double heigth, uint32_t fillColor, uint32_t outlineColor)
	: m_fillColor(fillColor)
	, m_outlineColor(outlineColor)
	, m_width(width)
	, m_heigth(heigth)
	, m_leftTop(leftTop)
{
	if (!(width > 0 && heigth > 0))
	{
		throw IncorrectData("the height and width of the rectangle must be greater than zero");
	}
}

// ISolidShape
double CRectangle::GetArea() const
{
	return m_width * m_heigth;
}

double CRectangle::GetPerimeter() const
{
	return (m_width * 2) + (m_heigth * 2);
}

std::string CRectangle::ToString() const
{
	std::stringstream areaAndPerimeter;
	areaAndPerimeter << "\nArea: " << CRectangle::GetArea() << "\nPerimeter: " << CRectangle::GetPerimeter();
	std::stringstream widthAndHeigth;
	widthAndHeigth << "\nWidth: " << m_width << "\nHeigth: " << m_heigth;
	return "Shape: rectangle\nFill color: #" + UInt32_tToHex(m_fillColor) + "\nOutline color: #" + UInt32_tToHex(m_outlineColor) + "\nLeft top: " + m_leftTop.Print() + widthAndHeigth.str() + areaAndPerimeter.str();
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return CPoint(m_leftTop.x + m_width, m_leftTop.y - m_heigth);
}

// CRectangle
double CRectangle::GetHeight() const
{
	return m_heigth;
}

double CRectangle::GetWidth() const
{
	return m_width;
}

void CRectangle::Draw(ICanvas& canvas) const
{
	std::vector<CPoint> points{
		m_leftTop,
		CPoint(m_leftTop.x + m_width, m_leftTop.y),
		CPoint(m_leftTop.x + m_width, m_leftTop.y + m_heigth),
		CPoint(m_leftTop.x, m_leftTop.y + m_heigth)
	};
	canvas.DrawLine(CPoint(m_leftTop.x - outlineSize, m_leftTop.y - outlineSize), CPoint(m_leftTop.x + m_width + outlineSize, m_leftTop.y - outlineSize), m_outlineColor);
	canvas.DrawLine(CPoint(m_leftTop.x + m_width, m_leftTop.y), CPoint(m_leftTop.x + m_width, m_leftTop.y + m_heigth + outlineSize), m_outlineColor);
	canvas.DrawLine(CPoint(m_leftTop.x - outlineSize, m_leftTop.y + m_heigth), CPoint(m_leftTop.x + m_width, m_leftTop.y + m_heigth), m_outlineColor);
	canvas.DrawLine(CPoint(m_leftTop.x - outlineSize, m_leftTop.y + m_heigth), CPoint(m_leftTop.x - outlineSize, m_leftTop.y - outlineSize), m_outlineColor);
	canvas.FillPolygon(points, m_fillColor);
}
