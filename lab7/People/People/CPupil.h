#pragma once
#include "CPersonImpl.h"
#include "IPupil.h"

class CPupil : public CPersonImpl<IPupil>
{
public:
	CPupil(const std::string& name,
		const std::string& lastName,
		const std::string& patronymic,
		const std::string& address,
		const std::string& schoolName,
		const std::string& schoolClass);
	
	std::string GetSchoolName() const;
	std::string GetSchoolClass() const;

	void SetSchoolName(const std::string& schoolName);
	void SetSchoolClass(const std::string& schoolClass);
	
private:
	std::string m_schoolName;
	std::string m_schoolClass;
};