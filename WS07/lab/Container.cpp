/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 11 / 11 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Container.h"
#include <string>

using namespace std;

namespace sdds {
	//Sets the Container to an invalid empty state
	void Container::setEmpty() {
		validContainer = false;

	}

	//returns the capacity of the container
	int Container::capacity() {
		return Capacity;
	}

	//returns the content volume of the container
	int Container::volume() {
		return ContentVol;
	}

	//constructor
	Container::Container(const char* content, int Capacity, int contentVolume) {
		if (content == NULL || contentVolume > Capacity) {
			validContainer = false;
			Content = nullptr; 
		}
		else {
			
			Content = new char[strlen(content) + 1];
			strcpy(Content, content);

			this->Capacity = Capacity;
			this->ContentVol = contentVolume;
			validContainer = true;
		}
	}
	Container::~Container() {
		delete[] Content;
	}

	int Container::operator += (int value) {
		if (ContentVol + value <= Capacity) {
			ContentVol += value;
		}
		else {
			value = Capacity - ContentVol;
			ContentVol = Capacity;
		}
		return value;
	}

	int Container::operator-= (int value) {
		if (ContentVol - value >= 0) {
			ContentVol -= value;
		}
		else {
			value = ContentVol;
			ContentVol = 0;
		}
		return value;
	}

	bool Container::valid() {
		return validContainer;
	}

	void Container::clear(int capacity, const char* content) {
		if (capacity > 0 && content != NULL && strlen(content) > 0) {
			delete[] this->Content;
			this->Content = new char[strlen(content) + 1];
			strcpy(this->Content, content);

			this->Capacity = capacity;
			this->ContentVol = 0;
			validContainer = true;
		}
	}


	ostream& Container::print(ostream& out) {
		if (validContainer) {
			out << Content << ": (" << ContentVol << "cc/" << Capacity << ")";
		}
		else {
			out << "****: (**cc/***)";
		}
		return out;
	}

	istream& Container::read(istream& in){
		int value;
		if (!validContainer) {
			cout << "Broken Container, adding aborted! Press <ENTER> to continue...." << endl;
			in.ignore();

		}
		else {
			bool validValue = false;
			cout << "Add to ";
			print(cout);
			while (!validValue) {
				cout << endl << "> ";
				in >> value;
				if (value > Capacity) {
					cout << "Invalid Integer, retry: ";
				}
				else if (value < 1 || value > 999) {
					cout << "Value out of range [1<=val<=999]: ";

				}
				else validValue = true;			
			}
			value = (*this += value);
			cout << "Added " << value << " CCs" << endl;
		}
		return in;
	}

}