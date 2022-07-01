#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint leftTop, double width, double heigth, uint32_t fillColor, uint32_t outlineColor);

	// ISolidShape
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	// CRectangle
	CPoint GetLeftTop() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;

	// ICanvasDrawable
	virtual void Draw(ICanvas& canvas) const override;

private:
	CPoint m_leftTop;
	double m_width = 1;
	double m_heigth = 1;
	uint32_t m_fillColor = 0;
	uint32_t m_outlineColor = 0;
};
