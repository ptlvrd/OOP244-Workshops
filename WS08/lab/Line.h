/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_LINE_H
#define SDDS_LINE_H_
#include "LblShape.h"

namespace sdds {
	class Line : public LblShape {
		int m_length=0;
	public:
		Line();
		Line(const char* label, int length);
		void getSpecs(std::istream& );
		void draw(ostream&) const;

	};
}
#endif // !SDDS_LINE_H
