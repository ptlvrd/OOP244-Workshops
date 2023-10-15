/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 07/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#define MAX_CONTENT_CHAR 70
#include<iostream>

namespace sdds {

	class Label
	{
	public:
		char* labelContent;
		char frame[9];
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::istream& readLabel(std::istream& ist = std::cin);
		std::ostream& printLabel(std::ostream& ostr = std::cout)const;
		Label& text(const char* content);
	};
}
#endif // SDDS_LABEL_H