#pragma once
#include "ICanvasDrawable.h"

class IShape : public ICanvasDrawable
{
public:
	virtual ~IShape() = default;
	virtual double GetArea() const = 0;
	virtual double GetPerimeter() const = 0;
	virtual std::string ToString() const = 0;
	virtual uint32_t GetOutlineColor() const = 0;
	
	// ICanvasDrawable
	virtual void Draw(ICanvas& canvas) const = 0;
};