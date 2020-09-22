#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using namespace std;

const string studentData[] =
{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Andrew,Butler,email@email.com,32,8,8,10,SOFTWARE"
};


void Roster::Add(string studentId, string fName, string lName, string studentEmail, int studentAge, int days1, int days2, int days3, Degree studentDegreeType) {
	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++) {
		if (classRosterArray[i] == nullptr) {
			if (studentDegreeType == SOFTWARE) {
				classRosterArray[i] = new SoftwareStudent(studentId, fName, lName, studentEmail, studentAge, days1, days2, days3, studentDegreeType);
				break;
			}
			else if (studentDegreeType == NETWORK) {
				classRosterArray[i] = new NetworkStudent(studentId, fName, lName, studentEmail, studentAge, days1, days2, days3, studentDegreeType);
				break;
			}
			else if (studentDegreeType == SECURITY) {
				classRosterArray[i] = new SecurityStudent(studentId, fName, lName, studentEmail, studentAge, days1, days2, days3, studentDegreeType);
				break;
			}
			else {
				cout << "Error, Unrecognised Degree type" << endl;
			}
			break;
		}

    }
}

void Roster::Remove(string studentID) {
	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++) {
		if (classRosterArray[i]->GetId() == studentID) {
			classRosterArray[i] = nullptr;
			break;
		}
	}
	cout << "Student with Id: " << studentID << " not found..." << endl;
}
void Roster::PrintAll() {
	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++) {
		classRosterArray[i]->Print();
	}
}
void Roster::PrintAverageDays(string studentID) {
	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++) {
		if (classRosterArray[i]->GetId() == studentID) {
			int sum = classRosterArray[i]->GetDaysToComplete()[0] + classRosterArray[i]->GetDaysToComplete()[1] + classRosterArray[i]->GetDaysToComplete()[2];
			int total = sum / 3;
			cout << studentID << "\t" << "Avererage Number of days to complete a class: " << total << endl;
			break;
		}
	}
	
}
void Roster::PrintInvalidEmails() {
	string email;
	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++) {
		email = classRosterArray[i]->GetEmail();
		if (email.find('.') == string::npos || email.find('@') == string::npos || email.find(' ') != string::npos){
			cout << email << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(Degree degreeName) {
	for (int i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[i])); i++) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeName) {
			classRosterArray[i]->Print();
		}
	}
}

int main() {
    cout << "Class: Scripting and Programing - c867" << endl;
    cout << "Language: C++" << endl;
    cout << "Student: Andrew Butler, 001053557" << endl;
    
    Roster* classRoster;

    classRoster = new Roster();
	for (int i = 0; i < (sizeof(studentData) / sizeof(studentData[i])); i++) {
		string outStream[9];
		string temp;
		Degree type;
		int x;
		x = 0;
		istringstream instream(studentData[i]);
		while (getline(instream, temp, ',')) {
			outStream[x] = temp;
			x++;
		}
		if (outStream[8] == "SOFTWARE") {
			type = SOFTWARE;
		}
		else if (outStream[8] == "SECURITY") {
			type = SECURITY;
		}
		else if (outStream[8] == "NETWORK") {
			type = NETWORK;
		}
		else {
			type = ERROR;
		}

			classRoster->Add(outStream[0], outStream[1], outStream[2], outStream[3], stoi(outStream[4]), stoi(outStream[5]), stoi(outStream[6]), stoi(outStream[7]), type);
	}
	
    cout << "Printing all entries... \n" << endl;
    
    classRoster->PrintAll();
    
    cout << "Printing invalid emails... \n" << endl;
    
    classRoster->PrintInvalidEmails();

    
    cout << "Printing average days to complete classes... \n" << endl;

    for(int i = 0; i < (sizeof(classRoster->classRosterArray) / sizeof(classRoster->classRosterArray[i])); i++) {
        classRoster->PrintAverageDays(classRoster->classRosterArray[i]->GetId());
    }
        
    cout << "Printing Software Students... \n" << endl;
    
    classRoster->PrintByDegreeProgram(SOFTWARE);

    classRoster->Remove("A3");
    classRoster->Remove("A3");

    delete classRoster;
	
    return 0;
}
