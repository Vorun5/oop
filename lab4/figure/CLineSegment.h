#pragma once
#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

	// CLineSegment
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

	// ICanvasDrawable
	virtual void Draw(ICanvas& canvas) const override;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;
	uint32_t m_outlineColor = 0;
};
