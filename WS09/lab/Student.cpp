/*Author	patel vrundaben vijaykumar
id - 158605220
date 23-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include"Student.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

namespace sdds {
	Student::Student() {
		age = 0;
		name = nullptr;
	}

	Student::Student(const char* stuName, int stuAge) {
		name = new char[strlen(stuName) + 1];
		strcpy(name, stuName);
		age = stuAge;
	}

	Student::Student(const Student& other) {
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		age = other.age;
	}

	Student& Student::operator=(Student& other) {
		if (this != &other) {
			delete[] name;
			name = new char[strlen(other.name) + 1];
			strcpy(name, other.name);
			age = other.age;

		}
		return *this;
	}

	Student::~Student() {
		delete[] name;
	}

	void Student::display() {
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
}