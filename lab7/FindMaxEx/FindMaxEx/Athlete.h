#pragma once
#include <string>

struct Athlete
{
	Athlete(const std::string& n, double w, int h)
		: name(n)
		, weight(w)
		, height(h){};
	std::string name;
	double weight;
	int height;
};

bool WeightComp(Athlete const& f, Athlete const& s)
{
	return (f.weight < s.weight);
}

bool HeightComp(Athlete const& f, Athlete const& s)
{
	return (f.height < s.height);
}

bool NameComp(Athlete const& f, Athlete const& s)
{
	return (f.name < s.name);
}