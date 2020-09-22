#include "student.h"

void Student::SetId(string studentId) {
    id = studentId;
    return;
}

void Student::SetFirstName(string fName) {
    firstName = fName;
    return;
}
void Student::SetLastName(string lName) {
    lastName = lName;
    return;
}
void Student::SetEmail(string studentEmail) {
    email = studentEmail;
    return;
}
void Student::SetAge(int studentAge) {
    age = studentAge;
    return;
}
void Student::SetDegree(Degree studentDegreeType) {
    return;
}
void Student::SetDaysToComplete(int days1, int days2, int days3) {
    daysToComplete[0] = days1;
    daysToComplete[1] = days2;
    daysToComplete[2] = days3;
    return;
}

string Student::GetId() {
    return id;
}
string Student::GetFirstName() {
    return firstName;
}
string Student::GetLastName() {
    return lastName;
}
string Student::GetEmail() {
    return email;
}
int Student::GetAge() {
    return age;
}
int *Student::GetDaysToComplete() {
    return daysToComplete;

}

void Student::Print() {
    return;
}
Degree Student::GetDegreeProgram() {
    return degreeType;
}


Student::Student(string studentId, string fName, string lName, string studentEmail, int studentAge, int days1, int days2, int days3, Degree studentDegreeType) {
    SetId(studentId);
    SetFirstName(fName);
    SetLastName(lName);
    SetEmail(studentEmail);
    SetAge(studentAge);
    SetDaysToComplete(days1, days2, days3);
}


Student::~Student() { }
