#pragma once

#include <string>
#include <vector>

#include "ICanvas.h"
#include <SFML/Graphics.hpp>

const float outlineSize = 3.f;

class CCanvas : public ICanvas
{
public:
	CCanvas(unsigned int width, unsigned int heigth);
	void Show() const;
	void Clear();

	// ICanvas
	void DrawLine(CPoint from, CPoint to, uint32_t lineColor) override;
	void FillPolygon(std::vector<CPoint> points, uint32_t fillColor) override;
	void DrawCirlce(CPoint center, double radius, uint32_t lineColor) override;
	void FillCirlce(CPoint center, double radius, uint32_t fillColor) override;

private:
	unsigned int m_width;
	unsigned int m_heigth;
	std::vector<std::unique_ptr<sf::Shape>> m_shapes;
};
