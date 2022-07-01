#include "CRational.h"

CRational::CRational()
	: m_numerator(0)
	, m_denominator(1)
{
}

CRational::CRational(int value)
	: m_numerator(value)
	, m_denominator(1)
{
}

CRational::CRational(int numerator, int denominator)
	: m_numerator(numerator)
	, m_denominator(denominator)
{
	if (m_denominator == 0)
	{
		throw std::invalid_argument("You cannot divide by zero");
	}

	if (m_denominator < 0)
	{
		m_denominator *= -1;
		m_numerator *= -1;
	}

	int gcd = std::gcd(m_numerator, m_denominator);
	m_numerator /= gcd;
	m_denominator /= gcd;
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return static_cast<double>(m_numerator) / static_cast<double>(m_denominator);
}

std::pair<int, CRational> CRational::ToCompoundFraction() const
{
	int wholePart = m_numerator / m_denominator;
	return std::pair<int, CRational>(wholePart, *this - wholePart);
}

CRational CRational::operator-() const
{
	return CRational(-m_numerator, m_denominator);
}

CRational CRational::operator+() const
{
	return *this;
}
// TODO: написать тест для переполнения
CRational operator+(CRational const& rational1, CRational const& rational2)
{
	int lcm = std::lcm(rational1.GetDenominator(), rational2.GetDenominator());
	return CRational
	(
		(rational1.GetNumerator() * (lcm / rational1.GetDenominator()))
		+
		(rational2.GetNumerator() * (lcm / rational2.GetDenominator())),
		lcm
	);
}

CRational operator-(CRational const& rational1, CRational const& rational2)
{
	return rational1 + (-rational2);
}

CRational operator*(CRational const& rational1, CRational const& rational2)
{
	return CRational(rational1.GetNumerator() * rational2.GetNumerator(), rational1.GetDenominator() * rational2.GetDenominator());
}

CRational operator/(CRational const& rational1, CRational const& rational2)
{
	if (rational2.GetNumerator() == 0)
	{
		throw std::invalid_argument("You cannot divide by zero");
	}
	return rational1 * CRational(rational2.GetDenominator(), rational2.GetNumerator());
}

CRational& CRational::operator+=(CRational const& rational)
{
	*this = *this + rational;
	return *this;
}

CRational& CRational::operator-=(CRational const& rational)
{
	*this = *this - rational;
	return *this;
}

CRational& CRational::operator*=(CRational const& rational)
{
	*this = *this * rational;
	return *this;
}

CRational& CRational::operator/=(CRational const& rational)
{
	*this = *this / rational;
	return *this;
}

bool CRational::operator==(CRational const& rational) const
{
	return GetNumerator() == rational.GetNumerator() && GetDenominator() == rational.GetDenominator();
}

bool CRational::operator!=(CRational const& rational) const
{
	return !(*this == rational);
}

bool operator<(CRational const& rational1, CRational const& rational2)
{
	// TODO: переполнение
	return (rational1.GetNumerator() * rational2.GetDenominator() < rational2.GetNumerator() * rational1.GetDenominator());
}

bool operator<=(CRational const& rational1, CRational const& rational2)
{
	return (rational1 < rational2) || (rational1 == rational2);
}

bool operator>(CRational const& rational1, CRational const& rational2)
{
	return !(rational1 <= rational2);
}

bool operator>=(CRational const& rational1, CRational const& rational2)
{
	return !(rational1 < rational2);
}

std::ostream& operator<<(std::ostream& stream, CRational const& rational)
{
	stream << rational.GetNumerator() << '/' << rational.GetDenominator();
	return stream;
}

std::istream& operator>>(std::istream& stream, CRational& rational)
{
	int numerator;
	int denominator;
	std::string a;
	stream >> a;

	if (stream >> numerator && stream.get() == '/' && stream >> denominator)
	{
		rational = CRational(numerator, denominator);
	}
	else
	{
		// TODO: возможно не нужно высталять этот статтус
		stream.setstate(std::ios_base::failbit);
	}

	return stream;
}
