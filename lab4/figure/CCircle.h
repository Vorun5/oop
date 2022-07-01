#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint center, double radius, uint32_t fillColor, uint32_t outlineColor);
	// ISolidShape
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	// CCircle
	CPoint GetCenter() const;
	double GetRadius() const;

	
	// ICanvasDrawable
	virtual void Draw(ICanvas& canvas) const override;


private:
	CPoint m_center;
	double m_radius = 1;
	uint32_t m_fillColor = 0;
	uint32_t m_outlineColor = 0;
};
