#pragma once
#include <vector>

#include "CPoint.h"

class ICanvas
{
public:
	virtual ~ICanvas() = default;
	virtual void DrawLine(CPoint from, CPoint to, uint32_t lineColor) = 0;
	virtual void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) = 0;
	virtual void DrawCirlce(CPoint center, double radius, uint32_t lineColor) = 0;
	virtual void FillCirlce(CPoint center, double radius, uint32_t fillColor) = 0;
};