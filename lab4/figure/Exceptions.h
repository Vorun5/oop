#pragma once
#include <iostream>

///  TODO: переименовать со словом error
struct IncorrectData : public std::logic_error
{
	IncorrectData(const char* what)
		: std::logic_error(what){};
};