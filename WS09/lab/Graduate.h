/*Author	patel vrundaben vijaykumar
id - 158605220
date 23-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_GRADUATE_H
#define SDDS_GRADUATE_H
#include "Student.h"

namespace sdds {
	class Graduate : public Student {
	private:
		char* supervisor;
		char* title;
	public:
		Graduate();
		Graduate(const char* stuName, int stuAge, const char* Thesistitle, const char* supervisorN);
		Graduate(const Graduate& other);
		Graduate& operator=(Graduate& other);
		~Graduate();
		void display();

	};
}

#endif // !SDDS_GRADUATE_H_
