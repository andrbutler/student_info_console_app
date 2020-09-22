#pragma once
#ifndef Roster_H
#define Roster_H

#include "student.h"
#include "stdafx.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "securityStudent.h"

using namespace std;

class Roster {
    public:
		
        void Add(string, string, string, string, int, int, int, int, Degree);
        void Remove(string studentID);
        void PrintAll();
        void PrintAverageDays(string studentID);
        void PrintInvalidEmails();
        void PrintByDegreeProgram(Degree);
		Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr};
};

#endif
