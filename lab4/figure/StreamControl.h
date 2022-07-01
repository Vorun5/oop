#pragma once

#include <istream>
#include <vector>
#include <string>
#include <sstream>
#include <optional>

#include "IShape.h"
#include "ColorConverter.h"
#include "CPoint.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"

bool ReadDoubleFromStream(std::istream& stream, double& number);

bool ReadColorFromStream(std::istream& stream, std::uint32_t& color);

bool ReadPointFromStream(std::istream& stream, CPoint& point);

std::optional<std::unique_ptr<CTriangle>> ReadTriangleFromStream(std::istream& stream);

std::optional<std::unique_ptr<CRectangle>> ReadRectangleFromStream(std::istream& stream);

std::optional<std::unique_ptr<CCircle>> ReadCircleFromStream(std::istream& stream);

std::optional<std::unique_ptr<CLineSegment>> ReadLineSegmentFromStream(std::istream& stream);

std::vector<std::unique_ptr<IShape>> ReadShapesFromStream(std::istream& stream, std::ostream& errorStream);