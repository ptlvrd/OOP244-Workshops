/*Author	patel vrundaben vijaykumar
id - 158605220
date 22-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Item.h"
#include <fstream>
#include <iomanip>

using namespace std;

namespace sdds {
	bool Item::linear() const{
		return m_linear;
	}

	Item::Item() {
		m_price = 0.0;
		m_qty = 0;
		m_qtyNeeded = 0;
		m_description = nullptr;
		m_linear = false;

	}

	Item::Item(Item& other) {
		*this = other;
	}

	Item& Item::operator=(Item& other) {
		if (this != &other) {
			m_price = other.m_price;
			m_qty = other.m_qty;
			m_qtyNeeded = other.m_qtyNeeded;
			m_description = new char[strlen(other.m_description) + 1];
			strcpy(m_description, other.m_description);
			m_state = other.m_state;
			m_sku = other.m_sku;

		}
		return *this;
	}

	Item::~Item() {
		delete[] m_description;
	}

	int Item::qtyNeeded() const {
		return m_qtyNeeded;
	}

	int Item::qty() const {
		return m_qty;
	}

	Item::operator double() const {
		return m_price;
	}

	Item::operator bool()const {
		return m_state;
	}

	int Item::operator-=(int qty) {
		m_qty -= qty;
		return m_qty;
	}

	int Item::operator+=(int qty) {
		m_qty += qty;
		return m_qty;
	}

	void Item::linear(bool linear) {
		m_linear = linear;
	}

	Status Item::clear() {
		return m_state = 0;
	}

	bool Item::operator==(int sku) const {
	
		return m_sku == sku;
	}

	bool Item::operator==(const char* description) const {
		return strstr(m_description, description);
	}

	std::ofstream& Item::save(std::ofstream& ofstr)const {
		if (m_state) {
			ofstr << m_sku << "\t" << m_description << "\t" << m_qty << "\t" << m_qtyNeeded << "\t" << fixed << setprecision(2) << m_price << endl;
		}
		return ofstr;
	}

	std::ifstream& Item::load(std::ifstream& ifstr) {
		delete[] m_description;
		m_description = nullptr;
		string string;
		ifstr >> m_sku;
		ifstr.ignore(1000, '\t');
		getline(ifstr, string, '\t');
		ifstr >> m_qty;
		ifstr.ignore(1000, '\t');
		ifstr >> m_qtyNeeded;
		ifstr.ignore(1000, '\t');
		ifstr >> m_price;

		ifstr.ignore(1);

		if (ifstr.fail()) {
			m_state = "Input file stream read failed!";

		}
		ut.alocpy(m_description, string.c_str());
		return ifstr;
	}

	std::ostream& Item::display(std::ostream& ostr) const{
		char* string = nullptr;
		if (!m_state) {
			ostr << m_state;
		}
		else {
			if (linear()) {
				ostr << setw(5) << left << m_sku << " | ";
				if (strlen(m_description) > 35) {
					ut.alocpy(string, m_description);
					string[35] = '\0';
					ostr << string;
					delete[] string;
					string = nullptr;
				}
				else {
					ostr << setw(35) << m_description;
				}

				ostr << " | " << setw(4) << right << m_qty << " | "
					<< setw(4) << right << m_qtyNeeded << " | "
					<< setw(7) << fixed << setprecision(2) << m_price << " |";

			}
			else {
				ostr << "AMA Item:" << endl;
				ostr << m_sku << ": " << m_description<< endl;
				ostr << "Quantity Needed: " << m_qtyNeeded << endl;
				ostr << "Quantity Available: " << m_qty << endl;
				ostr << "Unit Price: $" << fixed << setprecision(2) << m_price << endl;
				ostr << "Needed Purchase Fund: $" << fixed << setprecision(2) << m_price * (m_qtyNeeded - m_qty) << endl;

			}
		}
		return ostr;
	}

	int Item::readSku(std::istream& istr) {
		return m_sku = ut.getint(40000, 99999, "SKU: ");

	}
	std::istream& Item::read(std::istream& istr) {
		string string;
		delete[] m_description;
		m_description = nullptr;
		m_state = 0;
		cout << "AMA Item:" << endl << "SKU: " << m_sku << endl
			<< "Description: ";
		istr >> string;

		m_qtyNeeded = ut.getint(1, 9999, "Quantity Needed: ");
		m_qty = ut.getint(0, m_qtyNeeded, "Quantity On Hand: ");
		m_price = ut.getdouble(0.0, 9999.0, "Unit Price: $");
		
		if (istr.fail()) {
			m_state = "Console entry failed!";


		}
		ut.alocpy(m_description, string.c_str());
		return istr;
	}
}