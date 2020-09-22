#pragma once
#ifndef Network_Student_H
#define Network_Student_H
#include "student.h"
class NetworkStudent : public Student {
    public:
	   NetworkStudent(string, string, string, string, int, int, int, int, Degree);
       Degree GetDegreeProgram();
	   void Print();
    private:
       Degree degreeType;
};

#endif
