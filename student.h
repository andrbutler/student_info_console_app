#pragma once
#ifndef Student_H
#define Student_H

#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
    public:
        Student(string, string, string, string, int, int, int, int, Degree);
        
        void SetId(string);
        void SetFirstName(string);
        void SetLastName(string);
        void SetEmail(string);
        void SetAge(int);
        void SetDaysToComplete(int, int, int);
        void SetDegree(Degree);
        
        string GetId();
        string GetFirstName();
        string GetLastName();
        string GetEmail();
        int GetAge();
        int *GetDaysToComplete();

        virtual void Print();
        virtual Degree GetDegreeProgram();

        ~Student();

    protected:
        string id;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysToComplete[3];
        Degree degreeType;
    };
        
#endif
