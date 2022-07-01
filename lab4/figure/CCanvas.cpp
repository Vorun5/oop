#include <iostream>

#include "ColorConverter.h"
#include <corecrt_math_defines.h>

#include "CCanvas.h"
#include <SFML/Graphics.hpp>

CCanvas::CCanvas(unsigned int width, unsigned int heigth)
	: m_heigth(heigth)
	, m_width(width)
{
}

void CCanvas::Show() const
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow canvas(sf::VideoMode(m_width, m_heigth), "Canvas", sf::Style::Close, settings);

	while (canvas.isOpen())
	{

		sf::Event event;
		while (canvas.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				canvas.close();
		}

		canvas.clear(sf::Color(255, 255, 255));

		for (auto& shape : m_shapes)
		{
			canvas.draw(*shape.get());
		}

		canvas.display();
	}
}

void CCanvas::Clear()
{
	m_shapes.clear();
}

void CCanvas::DrawLine(CPoint from, CPoint to, uint32_t lineColor)
{
	RGB rgbLC = UInt32_tToRGB(lineColor);
	auto polygon = std::make_unique<sf::ConvexShape>();
	polygon->setPointCount(4);
	polygon->setFillColor(sf::Color(rgbLC.r, rgbLC.g, rgbLC.b));
	if (from.x == to.x)
	{
		polygon->setPoint(0, sf::Vector2f(from.x, from.y));
		polygon->setPoint(1, sf::Vector2f(from.x + outlineSize, from.y));
		polygon->setPoint(2, sf::Vector2f(to.x + outlineSize, to.y));
		polygon->setPoint(3, sf::Vector2f(to.x, to.y));
		m_shapes.push_back(std::move(polygon));
		return;
	}
	if (from.y == to.y)
	{
		polygon->setPoint(0, sf::Vector2f(from.x, from.y));
		polygon->setPoint(1, sf::Vector2f(from.x, from.y + outlineSize));
		polygon->setPoint(2, sf::Vector2f(to.x, to.y + outlineSize));
		polygon->setPoint(3, sf::Vector2f(to.x, to.y));
		m_shapes.push_back(std::move(polygon));
		return;
	}
	if (from.x > to.x)
	{
		CPoint buf = to;
		to = from;
		from = buf;
	}
	if (from.y > to.y)
	{
		polygon->setPoint(0, sf::Vector2f(from.x, from.y));
		polygon->setPoint(1, sf::Vector2f(from.x + outlineSize, from.y + outlineSize));
		polygon->setPoint(2, sf::Vector2f(to.x + outlineSize, to.y + outlineSize));
		polygon->setPoint(3, sf::Vector2f(to.x, to.y));
		m_shapes.push_back(std::move(polygon));
		return;
	}
	if (from.y < to.y)
	{
		polygon->setPoint(0, sf::Vector2f(from.x, from.y));
		polygon->setPoint(1, sf::Vector2f(from.x - outlineSize, from.y + outlineSize));
		polygon->setPoint(2, sf::Vector2f(to.x - outlineSize, to.y + outlineSize));
		polygon->setPoint(3, sf::Vector2f(to.x, to.y));
		m_shapes.push_back(std::move(polygon));
		return;
	}
}

void CCanvas::FillPolygon(std::vector<CPoint> points, uint32_t fillColor)
{
	RGB rgbFC = UInt32_tToRGB(fillColor);
	auto polygon = std::make_unique<sf::ConvexShape>();
	polygon->setPointCount(points.size());
	polygon->setFillColor(sf::Color(rgbFC.r, rgbFC.g, rgbFC.b));
	for (size_t i = 0; i < points.size(); i++)
	{
		polygon->setPoint(i, sf::Vector2f(points[i].x, points[i].y));
	}
	m_shapes.push_back(std::move(polygon));
}

void CCanvas::DrawCirlce(CPoint center, double radius, uint32_t lineColor)
{
	RGB rgbLC = UInt32_tToRGB(lineColor);
	auto circle = std::make_unique<sf::CircleShape>(radius, 30);
	circle->setOutlineColor(sf::Color(rgbLC.r, rgbLC.g, rgbLC.b));
	circle->setOutlineThickness(outlineSize);
	circle->setPosition(center.x - radius, center.y - radius);
	m_shapes.push_back(std::move(circle));
}

void CCanvas::FillCirlce(CPoint center, double radius, uint32_t fillColor)
{
	RGB rgbFC = UInt32_tToRGB(fillColor);
	auto circle = std::make_unique<sf::CircleShape>(radius);
	circle->setFillColor(sf::Color(rgbFC.r, rgbFC.g, rgbFC.b));
	circle->setPosition(center.x - radius, center.y - radius);
	m_shapes.push_back(std::move(circle));
}
