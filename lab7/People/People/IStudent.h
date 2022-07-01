#pragma once
#include "IPerson.h"

class IStudent : public IPerson
{
public:
	virtual std::string GetUniversityName() const = 0;
	virtual unsigned int GetStudentCardNumber() const = 0;

	virtual void SetUniversityName(const std::string& universityName) = 0;
	virtual void SetStudentCardNumber(unsigned int studentCardNumber) = 0;
};