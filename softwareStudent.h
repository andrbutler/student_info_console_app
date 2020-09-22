#pragma once
#ifndef Software_Student_H
#define Software_Student_H
#include "student.h"
class SoftwareStudent : public Student {
	public:
		SoftwareStudent(string, string, string, string, int, int, int, int, Degree);
		Degree GetDegreeProgram();
		void Print();
	private:
		Degree degreeType;
};

#endif