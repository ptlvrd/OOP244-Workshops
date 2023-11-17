/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 11 / 11 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>
#include <cstring>

using namespace std;

namespace sdds {
	class Container {
	private:
		char* Content;
		int Capacity;
		int ContentVol;
		bool validContainer;

	protected:
		void setEmpty();
		int capacity();
		int volume();

	public:
		Container(const char* content, int Capacity, int contentVolume = 0);
		~Container();
		int operator += (int value);
		int operator -= (int value);
		bool valid();

		void clear(int Capacity, const char* content);
		ostream& print(ostream& out);
		istream& read(istream& in);

		//Overload operator<< and operator>> to be able to print and read A container using cout and cin.
		friend ostream& operator << (ostream& out, Container& container) {
			return container.print(out);
		}
		friend istream& operator >> (istream& in, Container& container) {
			return container.read(in);
		}
 

	};

}

#endif