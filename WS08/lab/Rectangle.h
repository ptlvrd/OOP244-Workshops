/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_
#include "LblShape.h"
using namespace std;
namespace sdds {
	class Rectangle : public LblShape {
		int m_width=0;
		int m_height=0;
	public:
		Rectangle();
		Rectangle(const char* label, int width, int height);
		void getSpecs(istream&);
		void draw(ostream&) const;
	};
}

#endif // ! SDDS_RECTANGLE_H

