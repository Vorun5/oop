#pragma once
#include <iostream>

///  TODO: ������������� �� ������ error
struct IncorrectData : public std::logic_error
{
	IncorrectData(const char* what)
		: std::logic_error(what){};
};