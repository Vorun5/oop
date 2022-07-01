#include "CTeacher.h"
#include "CPersonImpl.h"

CTeacher::CTeacher(const std::string& name,
	const std::string& surname,
	const std::string& patronymic,
	const std::string& address,
	const std::string& schoolSubjectName)
	: CPersonImpl<ITeacher>(name, surname, patronymic, address)
	, m_schoolSubjectName(schoolSubjectName)
{
}

std::string CTeacher::GetSchoolSubjectName() const
{
	return m_schoolSubjectName;
}

void CTeacher::SetSchoolSubjectName(const std::string& schoolSubjectName)
{
	m_schoolSubjectName = schoolSubjectName;
}
