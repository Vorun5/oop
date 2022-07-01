#pragma once
#include "CPersonImpl.h"
#include "ITeacher.h"

class CTeacher : public CPersonImpl<ITeacher>
{
public:
	CTeacher(const std::string& name,
		const std::string& lastName,
		const std::string& patronymic,
		const std::string& address,
		const std::string& schoolSubjectName);
	
	std::string GetSchoolSubjectName() const override;
	void SetSchoolSubjectName(const std::string& schoolSubjectName) override;
	
private:
	std::string m_schoolSubjectName;
};
