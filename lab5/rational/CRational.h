#pragma once
#include "iostream"
#include <math.h>
#include <numeric>

class CRational
{
public:
	CRational();

	CRational(int value);

	CRational(int numerator, int denominator);

	int GetNumerator() const;

	int GetDenominator() const;

	double ToDouble() const;


	std::pair<int, CRational> ToCompoundFraction() const;

	CRational operator-() const;
	CRational operator+() const;
	CRational& operator+=(CRational const& rational);
	CRational& operator-=(CRational const& rational);
	CRational& operator*=(CRational const& rational);
	CRational& operator/=(CRational const& rational);

	bool operator==(CRational const& rational) const;
	bool operator!=(CRational const& rational) const;

private:
	int m_numerator;
	int m_denominator;
};

CRational operator+(CRational const& rational1, CRational const& rational2);
CRational operator-(CRational const& rational1, CRational const& rational2);
CRational operator*(CRational const& rational1, CRational const& rational2);
CRational operator/(CRational const& rational1, CRational const& rational2);

bool operator<(CRational const& rational1, CRational const& rational2);
bool operator<=(CRational const& rational1, CRational const& rational2);
bool operator>(CRational const& rational1, CRational const& rational2);
bool operator>=(CRational const& rational1, CRational const& rational2);

std::ostream& operator<<(std::ostream& stream, CRational const& rational);
std::istream& operator>>(std::istream& stream, CRational& rational);
