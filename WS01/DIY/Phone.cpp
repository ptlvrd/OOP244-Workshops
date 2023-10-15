/* name- patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id- 158605220
* date- 14/09/2023
* citations; 
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Phone.h"
#include <iostream>
#include <stdio.h>


using namespace std;
using namespace sdds;

namespace sdds {
	// runs the phone directory application
	void phoneDir(const char* programTitle, const char* fileName) {
		cout << programTitle << " phone direcotry search" << endl;
		cout << "-------------------------------------------------------" << endl;
		FILE* file = fopen(fileName, "r");
		if (!file) {
			cout << fileName << "file not found!" << endl;
			cout << "Thank you for using " << programTitle << "directory." << endl;
			return;
		}
		while (true) {
			char str[51] = { 0 }, find[51] = { 0 };
			cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
			cout << "> ";
			cin >> str;
			if (str == "!")
				break;

			char name[51] = { 0 }, tempFind[51] = { 0 }, number[5] = { 0 };
			int area, prefix;
			while (fscanf(file, "%[^\t]\t%d\t%d\t%s\n", name, &area, &prefix, number)!=EOF)
            {
				toLowerCaseAndCopy(tempFind, name);
				toLowerCaseAndCopy(find, str);
				if(strStr(tempFind, find))
					cout << name << ": (" << area << ") " << prefix << "-" << number << endl;

			}
			rewind(file);

		}
		fclose(file);
        cout << "Thank you for using " << programTitle << " directory." << endl;
	}
}