#pragma once
#ifndef Security_Student_H
#define Security_Student_H
#include "student.h"
class SecurityStudent : public Student {
	public:
		SecurityStudent(string, string, string, string, int, int, int, int, Degree);
		Degree GetDegreeProgram();
		void Print();
	private:
		Degree degreeType;
};

#endif