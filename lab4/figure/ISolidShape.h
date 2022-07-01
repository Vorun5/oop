#pragma once
#include <string>

#include "IShape.h"

class ISolidShape : public IShape
{
public:
	virtual ~ISolidShape() = default;
	virtual uint32_t GetFillColor() const = 0;

	// IShape
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;

	// ICanvasDrawable
	virtual void Draw(ICanvas& canvas) const = 0;
};
