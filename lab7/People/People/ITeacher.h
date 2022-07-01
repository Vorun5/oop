#pragma once
#include "IPerson.h"

class ITeacher : public IPerson
{
public:
	virtual ~ITeacher() = default;
	virtual std::string GetSchoolSubjectName() const = 0;
	virtual void SetSchoolSubjectName(const std::string& schoolSubjectName) = 0;
};