/*Author	patel vrundaben vijaykumar
id - 158605220
date 23-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_STUDENT_H
#define SDDS_STUDENT_H

namespace sdds {
	class Student {
	private:
		int age;
		char* name;
	public:
		Student();
		Student(const char* stuName, int stuAge);
		Student(const Student& other);
		Student& operator=(Student& other);
		virtual ~Student();
		void display();
	};
}
#endif // !SDDS_STUDENT_H_
