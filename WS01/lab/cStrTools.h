/* name- patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id- 158605220
* date- 11/09/2023 
*
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*
*/
#ifndef SDDS_cStrTools_H 
#define SDDS_cStrTools_H
namespace sdds {

	char toLower(char ch);
	int strCmp(const char* s1, const char* s2);
	int strnCmp(const char* s1, const char* s2, int len);
	const char* strStr(const char* str, const char* find);
	void strCpy(char* des, const char* src);
	int strLen(const char* str);
	int isAlpha(char ch);
	int isSpace(char ch);
	void trim(char word[]);
	void toLowerCaseAndCopy(char des[], const char source[]);


}
#endif
