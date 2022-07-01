#pragma once
#include "CPersonImpl.h"

template <class Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(const std::string& name,
		const std::string& lastName,
		const std::string& patronymic,
		const std::string& address,
		const std::string& universityName,
		unsigned int studentCardNumber)
		: CPersonImpl<Base>(name, lastName, patronymic, address)
		, m_universityName(universityName)
		, m_studentCardNumber(studentCardNumber)
	{
	}
	
	std::string GetUniversityName() const override
	{
		return m_universityName;
	}

	unsigned int GetStudentCardNumber() const override
	{
		return m_studentCardNumber;
	}

	void SetUniversityName(const std::string& universityName) override
	{
		m_universityName = universityName;
	}

	void SetStudentCardNumber(unsigned int studentCardNumber) override
	{
		m_studentCardNumber = studentCardNumber;
	}

private:
	std::string m_universityName;
	unsigned int m_studentCardNumber;
};