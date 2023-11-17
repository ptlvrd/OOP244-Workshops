/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 11 / 11 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
using namespace sdds;
namespace sdds {
	class Pack : public Container{
	private:
		int unitSize;
		int Size;
		int numberofUnits;

	public:
		Pack(const char* content, int size, int unitsize = 330, int numberofunits = 0);
		~Pack();
		int operator += (int units);
		int operator -= (int units);

		int unit();
		int noOfUntis();
		int size();
		
		void clear(int packsize, int unitsize, const char* content);
		ostream& print(ostream& ostr);
		istream& read(istream& istr);

		//Insertions and extraction helper operator overloads
		friend ostream& operator << (ostream& ostr, Pack& pack) {
			return pack.print(ostr);
		}

		friend istream& operator >> (istream& istr, Pack& pack) {
			return pack.read(istr);
		}
	};
}
#endif