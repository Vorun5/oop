#include "CAdvancedStudent.h"
#include "CPersonImpl.h"

CAdvancedStudent::CAdvancedStudent(const std::string& name,
	const std::string& lastName,
	const std::string& patronymic,
	const std::string& address,
	const std::string& universityName,
	unsigned int studentTicketNumber,
	const std::string& dissertationTopic)
	: CStudentImpl<IAdvancedStudent>(name, lastName, patronymic, address, universityName, studentTicketNumber)
	, m_dissertationTopic(dissertationTopic)
{
}

std::string CAdvancedStudent::GetDissertationTopic() const
{
	return m_dissertationTopic;
}

void CAdvancedStudent::SetDissertationTopic(const std::string& dissertationTopic)
{
	m_dissertationTopic = dissertationTopic;
}