#pragma once
#include "CStudentImpl.h"
#include "IStudent.h"

class CStudent : public CStudentImpl<IStudent>
{
public:
	CStudent(const std::string& name,
		const std::string& lastNmae,
		const std::string& patronymic,
		const std::string& address,
		const std::string& universityName,
		unsigned int studentCardNumber);
};