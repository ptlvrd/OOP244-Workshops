/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 11 / 11 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Pack.h"
#include <string>

using namespace std;

namespace sdds {
	Pack::Pack(const char* content, int Size, int unitsize, int numberofunits) : Container(content, Size* unitsize, numberofunits* unitsize) {
		this->Size = Size;
		this->unitSize = unitsize;
		this->numberofUnits = numberofunits;
	}
	Pack::~Pack() {
		
	}

	int Pack::operator += (int units) {
		int addUnits = Container::operator+=(units * unitSize) / unitSize;
		this->numberofUnits += addUnits;
		return addUnits;
	}

	int Pack::operator -= (int units) {
		int removeUnits = Container::operator-=(units * unitSize) / unitSize;
		this->numberofUnits -= removeUnits;
		return removeUnits;
	}

	int Pack::unit() {
		return unitSize;
	}

	int Pack::noOfUntis() {
		return numberofUnits;
	}

	int Pack::size() {
		return Size;
	}

	void Pack::clear(int packsize, int unitsize, const char* content) {
		if (unitsize > 0) {
			int product = packsize * unitsize;
			Size = packsize;
			Container::clear(product, content);
			this->unitSize = unitsize;
			this->numberofUnits = 0;
		}
	}

	ostream& Pack::print(ostream& ostr) {
		Container::print(ostr);
		if (valid()) {
			ostr << ", " << numberofUnits << " in a pack of " << Size;
		}
		return ostr;
	}

	istream& Pack::read(istream& istr) {
		int units;
		if (!valid()) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore();
		}
		else if (numberofUnits == Size) {
			istr.ignore();
			cout << "Pack is full!, press <ENTER> to continue..." << endl;
			
		}
		else {
			bool valid = false;
			cout << "Add to ";
			print(cout);

			int value = Size - numberofUnits;
			int flag = 0;
			while (!valid && flag == 0) {
				cout << endl << "> ";
				istr >> units;

				if (units > Size) {
					cout << "Invalid Integer, retry: ";

				}
				else if (units < 1 || units > value) {
					cout << "Value out of range [1<=val<=" << value << "]: ";
					istr >> units;
					flag = 1;
				}
				else valid = true;
			}
			units = (*this += units);
			cout << "Added " << units << endl;
		}
		return istr;
	}
	
}