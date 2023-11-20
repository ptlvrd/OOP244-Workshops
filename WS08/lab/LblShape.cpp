/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "LblShape.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
namespace sdds {
	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) {
		delete[] m_label;
		m_label = new char[strlen(label) + 1];
		strcpy(m_label, label);
	}

	LblShape::~LblShape() {
		delete[] m_label;
	}

	void LblShape::getSpecs(istream& is) {
		string flag;
		getline(is, flag, ',');
		delete[] m_label;
		m_label = new char[strlen(flag.c_str()) + 1];
		strcpy(m_label, flag.c_str());
	}

}