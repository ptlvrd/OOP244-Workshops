/*Author	patel vrundaben vijaykumar
id - 158605220
date 22-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
#include <iostream>
#include "iProduct.h"
#include "Status.h"
#include <fstream>

#include "Utils.h"
using namespace std;
namespace sdds {
	class Item : public iProduct {
	private:
		double m_price;
		int m_qty;
		int m_qtyNeeded;
	    char* m_description;
		bool m_linear;
		
	protected:
		Status m_state;
		int m_sku;
		bool linear()const;
	public:
		Item();
		Item(Item &other);
		Item& operator=(Item& other);
		~Item();

		int qtyNeeded()const;
		int qty()const;
		operator double()const;
		operator bool()const;

		int operator-=(int qty);
		int operator+=(int qty);
		void linear(bool linear);
		Status clear();

		bool operator==(int sku)const;
		bool operator==(const char* description)const;

		std::ofstream& save(std::ofstream& ofstr)const;
		std::ifstream& load(std::ifstream& ifstr);
		std::ostream& display(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);

		int readSku(std::istream& istr);
		 



	};
}
#endif //!SDDS_ITEM_H_