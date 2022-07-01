#include "ColorConverter.h"
#include <sstream>
#include <iomanip>

bool HexToUInt32_t(const std::string& hex, uint32_t& color)
{
	size_t size = 6;
	if (hex.size() == size)
	{
		std::istringstream hexStream(hex);
		uint32_t result;
		if (hexStream >> std::hex >> result)
		{
			color = result;
			return true;
		}
	}
	return false;
}

std::string UInt32_tToHex(uint32_t color)
{
	if (color >= 16777215)
	{
		return "ffffff";
	}
	std::stringstream stream;
	stream << std::setfill('0') << std::setw(6) << std::hex << color;
	return stream.str();
}

RGB UInt32_tToRGB(uint32_t color)
{
	RGB rgb;
	rgb.r = (color & 0xff0000) >> 16;
	rgb.g = (color & 0x00ff00) >> 8;
	rgb.b = (color & 0x0000ff);
	return rgb;
}