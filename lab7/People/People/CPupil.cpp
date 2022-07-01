#include "CPupil.h"

CPupil::CPupil(const std::string& name,
	const std::string& lastName,
	const std::string& patronymic,
	const std::string& address,
	const std::string& schoolName,
	const std::string& schoolClass)
	: CPersonImpl<IPupil>(name, lastName, patronymic, address)
	, m_schoolName(schoolName)
	, m_schoolClass(schoolClass)
{
}

std::string CPupil::GetSchoolName() const
{
	return m_schoolName;
}

std::string CPupil::GetSchoolClass() const
{
	return m_schoolClass;
}

void CPupil::SetSchoolName(const std::string& schoolName)
{
	m_schoolName = schoolName;
}

void CPupil::SetSchoolClass(const std::string& schoolClass)
{
	m_schoolClass = schoolClass;
}