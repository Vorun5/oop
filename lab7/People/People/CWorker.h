#pragma once
#include "CPersonImpl.h"
#include "IWorker.h"

class CWorker : public CPersonImpl<IWorker>
{
public:
	CWorker(const std::string& name,
		const std::string& lastName,
		const std::string& patronymic,
		const std::string& address,
		const std::string& specialty);
	
	std::string GetSpecialty() const override;
	void SetSpecialty(const std::string& specialty) override;
	
private:
	std::string m_specialty;
};