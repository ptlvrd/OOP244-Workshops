/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "Line.h"
#include <iostream>
#include <iomanip>
using namespace std;
namespace sdds {
	Line::Line() {
		m_length = 0;
	}

	Line::Line(const char* label, int length) : LblShape(label), m_length(length) {
		//m_length = length;
	}

	void Line::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(1000, '\n');
	}

	void Line::draw(ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++) {
				os << "=";
			}
			//os << endl;
		}
	}
	
}