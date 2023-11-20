/*Author	patel vrundaben vijaykumar
id - 158605220
date 17-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_
#include "Shape.h"

namespace sdds {
	class LblShape : public Shape {
		char* m_label=nullptr;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		~LblShape();
		LblShape(const LblShape&) = delete;
		void operator=(const LblShape&) = delete;
		void getSpecs(istream& is);

    };
}
#endif // !SDDS_LBLSHAPE_H

