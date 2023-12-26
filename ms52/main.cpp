/***********************************************************************
// Final project Milestone 52
//
// File: main52.cpp
// Version 1.0
// Author  Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name patel vrundaben vijaykumar                 Date  06/12/2023          Reason
***********************************************************************/
#include <iostream>
#include <fstream>
#include "AidMan.h"
#include "Utils.h"
using namespace sdds;
using namespace std;

void copyfile(const char* to, const char* from);
void displayFile(const char* file);

int main() {
	copyfile("data.dat", "data52.dat");
	ut.testMode();
	AidMan().run();
	displayFile("data.dat");
	return 0;
}

void displayFile(const char* file) {
	ifstream in(file);
	char ch;
	cout << "File: " << file << endl;
	while (in.get(ch)) cout << ch;
}

void copyfile(const char* to, const char* from) {
	std::ifstream in(from);
	std::ofstream out(to);
	char ch;
	while (in.get(ch)) out.put(ch);
}