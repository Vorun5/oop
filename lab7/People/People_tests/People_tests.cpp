#define CATCH_CONFIG_MAIN

#include "../../../cath/catch.hpp"
#include "../People/CPupil.h"
#include "../People/CStudent.h"
#include "../People/CWorker.h"
#include "../People/CTeacher.h"
#include "../People/CAdvancedStudent.h"

SCENARIO("CPupil tests") {
	CPupil pupil("Firdavsi", "Nurov", "Sultonbekovich", "Yoshkar Ola", "School 1", "11a");
	REQUIRE(pupil.GetName() == "Firdavsi");
	REQUIRE(pupil.GetLastName() == "Nurov");
	REQUIRE(pupil.GetPatronymic() == "Sultonbekovich");
	REQUIRE(pupil.GetAddress() == "Yoshkar Ola");
	REQUIRE(pupil.GetSchoolName() == "School 1");
	REQUIRE(pupil.GetSchoolClass() == "11a");
	pupil.SetName("F");
	pupil.SetLastName("N");
	pupil.SetPatronymic("S");
	pupil.SetAddress("Y");
	pupil.SetSchoolName("S1");
	pupil.SetSchoolClass("10a");
	REQUIRE(pupil.GetName() == "F");
	REQUIRE(pupil.GetLastName() == "N");
	REQUIRE(pupil.GetPatronymic() == "S");
	REQUIRE(pupil.GetAddress() == "Y");
	REQUIRE(pupil.GetSchoolName() == "S1");
	REQUIRE(pupil.GetSchoolClass() == "10a");
}

SCENARIO("CTeacher tests")
{
	CTeacher teacher("Firdavsi", "Nurov", "Sultonbekovich", "Yoshkar Ola", "Math");
	REQUIRE(teacher.GetName() == "Firdavsi");
	REQUIRE(teacher.GetLastName() == "Nurov");
	REQUIRE(teacher.GetPatronymic() == "Sultonbekovich");
	REQUIRE(teacher.GetAddress() == "Yoshkar Ola");
	REQUIRE(teacher.GetSchoolSubjectName() == "Math");
	teacher.SetName("F");
	teacher.SetLastName("N");
	teacher.SetPatronymic("S");
	teacher.SetAddress("Y");
	teacher.SetSchoolSubjectName("M");
	REQUIRE(teacher.GetName() == "F");
	REQUIRE(teacher.GetLastName() == "N");
	REQUIRE(teacher.GetPatronymic() == "S");
	REQUIRE(teacher.GetAddress() == "Y");
	REQUIRE(teacher.GetSchoolSubjectName() == "M");
}

SCENARIO("CStudent tests")
{
	CStudent student("Firdavsi", "Nurov", "Sultonbekovich", "Yoshkar Ola", "Volgotech", 123456);
	REQUIRE(student.GetName() == "Firdavsi");
	REQUIRE(student.GetLastName() == "Nurov");
	REQUIRE(student.GetPatronymic() == "Sultonbekovich");
	REQUIRE(student.GetAddress() == "Yoshkar Ola");
	REQUIRE(student.GetUniversityName() == "Volgotech");
	REQUIRE(student.GetStudentCardNumber() == 123456);
	student.SetName("F");
	student.SetLastName("N");
	student.SetPatronymic("S");
	student.SetAddress("Y");
	student.SetUniversityName("V");
	student.SetStudentCardNumber(54321);
	REQUIRE(student.GetName() == "F");
	REQUIRE(student.GetLastName() == "N");
	REQUIRE(student.GetPatronymic() == "S");
	REQUIRE(student.GetAddress() == "Y");
	REQUIRE(student.GetUniversityName() == "V");
	REQUIRE(student.GetStudentCardNumber() == 54321);
}

SCENARIO("CAdvancedStudent tests")
{
	CAdvancedStudent advancedStudent("Firdavsi", "Nurov", "Sultonbekovich", "Yoshkar Ola", "Volgotech", 123456, "Cats");
	REQUIRE(advancedStudent.GetName() == "Firdavsi");
	REQUIRE(advancedStudent.GetLastName() == "Nurov");
	REQUIRE(advancedStudent.GetPatronymic() == "Sultonbekovich");
	REQUIRE(advancedStudent.GetAddress() == "Yoshkar Ola");
	REQUIRE(advancedStudent.GetUniversityName() == "Volgotech");
	REQUIRE(advancedStudent.GetStudentCardNumber() == 123456);
	REQUIRE(advancedStudent.GetDissertationTopic() == "Cats");
	advancedStudent.SetName("F");
	advancedStudent.SetLastName("N");
	advancedStudent.SetPatronymic("S");
	advancedStudent.SetAddress("Y");
	advancedStudent.SetUniversityName("V");
	advancedStudent.SetStudentCardNumber(54321);
	advancedStudent.SetDissertationTopic("C");
	REQUIRE(advancedStudent.GetName() == "F");
	REQUIRE(advancedStudent.GetLastName() == "N");
	REQUIRE(advancedStudent.GetPatronymic() == "S");
	REQUIRE(advancedStudent.GetAddress() == "Y");
	REQUIRE(advancedStudent.GetUniversityName() == "V");
	REQUIRE(advancedStudent.GetStudentCardNumber() == 54321);
	REQUIRE(advancedStudent.GetDissertationTopic() == "C");
}

SCENARIO("CWorker tests")
{
	CWorker worker("Firdavsi", "Nurov", "Sultonbekovich", "Yoshkar Ola", "Programmer");
	REQUIRE(worker.GetName() == "Firdavsi");
	REQUIRE(worker.GetLastName() == "Nurov");
	REQUIRE(worker.GetPatronymic() == "Sultonbekovich");
	REQUIRE(worker.GetAddress() == "Yoshkar Ola");
	REQUIRE(worker.GetSpecialty() == "Programmer");
	worker.SetName("F");
	worker.SetLastName("N");
	worker.SetPatronymic("S");
	worker.SetAddress("Y");
	worker.SetSpecialty("P");
	REQUIRE(worker.GetName() == "F");
	REQUIRE(worker.GetLastName() == "N");
	REQUIRE(worker.GetPatronymic() == "S");
	REQUIRE(worker.GetAddress() == "Y");
	REQUIRE(worker.GetSpecialty() == "P");
}