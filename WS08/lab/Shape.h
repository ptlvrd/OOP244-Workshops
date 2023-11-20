/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
using namespace std;
namespace sdds {
	class Shape {
	public:
		virtual void draw(ostream&) const = 0;
		virtual void getSpecs(istream&) = 0;
		virtual ~Shape() {};
	};

	ostream& operator<<(ostream& os, const Shape& shape);
    istream& operator>>(istream& is, Shape& shape);
}

#endif // !DDS_SHAPE_H_
