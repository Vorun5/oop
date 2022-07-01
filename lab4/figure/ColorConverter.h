#pragma once
#include <cstdint>
#include <string>

struct RGB
{
	std::uint8_t r;
	std::uint8_t g;
	std::uint8_t b;
};

bool HexToUInt32_t(const std::string& hex, uint32_t& color);

std::string UInt32_tToHex(uint32_t color);

RGB UInt32_tToRGB(uint32_t color);