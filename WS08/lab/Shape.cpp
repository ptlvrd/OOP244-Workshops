/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "Shape.h"
#include <iostream>

using namespace std;

namespace sdds {
	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}

}