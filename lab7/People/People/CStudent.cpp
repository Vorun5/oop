#include "CStudent.h"

CStudent::CStudent(const std::string& name,
	const std::string& lastName,
	const std::string& patronymic,
	const std::string& address,
	const std::string& universityName,
	unsigned int studentCardNumber)
	: CStudentImpl<IStudent>(name, lastName, patronymic, address, universityName, studentCardNumber)
{}