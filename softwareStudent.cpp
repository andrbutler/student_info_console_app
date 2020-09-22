#include "softwareStudent.h"

SoftwareStudent::SoftwareStudent(string studentId, string fName, string lName, string studentEmail, int studentAge, int days1, int days2, int days3, Degree studentDegreeType) : Student::Student(studentId, fName, lName, studentEmail, studentAge, days1, days2, days3, studentDegreeType) {
degreeType = studentDegreeType;
}
Degree SoftwareStudent::GetDegreeProgram() {
	return degreeType;
}

void SoftwareStudent::Print() {
	cout << GetId() << "\t" << "First Name: " << GetFirstName() << "\t" << "Last Name: " << GetLastName() << "\t" << "Age: " << GetAge() << "\t" << "Email: " << GetEmail() << "\t"
		<< "daysInCourse: {" << GetDaysToComplete()[0] << ", " << GetDaysToComplete()[1] << ", " << GetDaysToComplete()[2] << "}" << "\t" << "Degree Program: Software" << endl;
}




