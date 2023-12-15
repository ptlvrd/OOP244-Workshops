/*Author	patel vrundaben vijaykumar
id - 158605220
date 23-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "Graduate.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace sdds {
	Graduate::Graduate() {
		title = nullptr;
		supervisor = nullptr;
	}

    Graduate::Graduate(const char* stuName, int stuAge, const char* Thesistitle, const char* supervisorN) :Student(stuName, stuAge){
        
        title = new char[strlen(Thesistitle) + 1];
        strcpy(title, Thesistitle);

        supervisor = new char[strlen(supervisorN) + 1];
        strcpy(supervisor, supervisorN);

       
    }

    Graduate::Graduate(const Graduate& other): Student(other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        supervisor = new char[strlen(other.supervisor) + 1];
        strcpy(supervisor, other.supervisor);
    }

    Graduate& Graduate::operator=(Graduate& other) {
        if (this != &other) {
            Student::operator=(other);
            delete[] supervisor;
            delete[] title;

            title = new char[strlen(other.title) + 1];
            strcpy(title, other.title);

            supervisor = new char[strlen(other.supervisor) + 1];
            strcpy(supervisor, other.supervisor);

        }
        return *this;
    }

    Graduate::~Graduate() {
        delete[] supervisor;
        supervisor = nullptr;
        delete[] title;
        title = nullptr;
    }

    void Graduate::display() {
        Student::display();
        cout << "Thesis Title: " << title << endl;
        cout << "Supervisor: " << supervisor << endl;
        cout << "---------------------------------------------" << endl;
    }

}