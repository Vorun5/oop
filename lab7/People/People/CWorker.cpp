#include "CWorker.h"
#include "CPersonImpl.h"

CWorker::CWorker(const std::string& name,
	const std::string& lastName,
	const std::string& patronymic,
	const std::string& address,
	const std::string& specialty)
	: CPersonImpl<IWorker>(name, lastName, patronymic, address)
	, m_specialty(specialty)
{}

std::string CWorker::GetSpecialty() const
{
	return m_specialty;
}

void CWorker::SetSpecialty(const std::string& specialty)
{
	m_specialty = specialty;
}