/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "Rectangle.h"
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
namespace sdds {
	Rectangle::Rectangle() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* label, int width, int height) : LblShape(label), m_width(width), m_height(height) {
		
		if ((m_height < 3) || (m_width < int(strlen(label) + 2))) {
			m_height = 0;
			m_width = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1000, ',');
		is >> m_height;
		is.ignore(1000, '\n');
	}

	void Rectangle::draw(ostream& os) const {
		if (m_height > 0 /* || m_width > 0 || label() != nullptr*/) {
			os << "+" << setw(m_width - 2) << setfill('-') << "-"<< "+" << endl;
			os << "|" << setw(m_width - 2) << setfill(' ') << left << label() << "|" << endl;
			for (int i = 0; i < m_height - 3; i++)
				os << "|" << setw(m_width - 2) << setfill(' ') << " " << "|" << endl;
			
			os << "+" << setw(m_width - 2) << setfill('-') << "-" << "+";

		}
	}
}