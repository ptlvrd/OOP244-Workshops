/*Author	patel vrundaben vijaykumar
id - 158605220
date 29-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include "Perishable.h"

namespace sdds {

    Perishable::Perishable() : Item(), m_handling(nullptr) {}

    Perishable::Perishable(const Perishable& src) : Item(src) {
        m_handling = nullptr;
        *this = src;
    }

    Perishable::~Perishable() {
        delete[] m_handling;
    }

    Perishable& Perishable::operator=(const Perishable& src) {
        if (this != &src) {
            Item::operator=(src);
            delete[] m_handling;
            m_handling = nullptr;

            m_expiry = src.m_expiry;


            if (src.m_handling != nullptr) {
                m_handling = new char[strlen(src.m_handling) + 1];
                strcpy(m_handling, src.m_handling);
            }
        }
        return *this;
    }

    const Date& Perishable::expiry() const {
        return m_expiry;
    }

    Perishable::operator bool() const {
        return m_sku != 0;
    }

    std::istream& Perishable::read(std::istream& istr) {
        Item::read(istr);
        delete[] m_handling;
        m_handling = nullptr;

        std::cout << "Expiry date (YYMMDD): ";
        istr >> m_expiry;
        istr.ignore();
        std::cout << "Handling Instructions, ENTER to skip: ";
        char firstChar = istr.peek();
        if (firstChar != '\n') {
            m_handling = new char[1000];
            istr.getline(m_handling, 1000);
        }
        else {
            istr.ignore();
        }


        if (istr.fail()) {
            m_state = "Perishable console date entry failed!";
        }

        return istr;
    }

    std::ostream& Perishable::display(std::ostream& ostr) const {
        if (!m_state) {
            ostr << m_state;
        }
        else {
            if (Item::linear()) {
                Item::display(ostr);

                ostr << (m_handling && *m_handling ? '*' : ' ');
                ostr << m_expiry;
            }
            else {
                ostr << "Perishable ";
                Item::display(ostr);
                ostr << "Expiry date: ";
                ostr << m_expiry;
                std::cout << std::endl<<endl;
                if (m_handling && *m_handling) {
                    ostr << "Handling Instructions: " << m_handling << std::endl;
                }
            }
        }
        return ostr;
    }

    std::ofstream& Perishable::save(std::ofstream& ofstr) const {
        if (m_state) {
            Item::save(ofstr);


            if (m_handling != nullptr) {
                ofstr << m_handling << "\t";
            }
            else {
                ofstr << "";
            }
            ofstr << std::setw(2) << std::setfill('0') << (m_expiry.Year % 100)
                << std::setw(2) << std::setfill('0') << m_expiry.Month
                << std::setw(2) << std::setfill('0') << m_expiry.Day;

            return ofstr;
        }
        return ofstr;
    }

    std::ifstream& Perishable::load(std::ifstream& ifstr) {
        Item::load(ifstr);

        if (ifstr.fail()) {
            m_state = "Input file stream read (perishable) failed!";
            return ifstr;
        }

        delete[] m_handling;
        m_handling = nullptr;


        char temp[1000];

        if (ifstr.getline(temp, 1000, '\t') && isalpha(temp[0])) {
            m_handling = new char[strlen(temp) + 1];
            strcpy(m_handling, temp);
        }

        ifstr >> m_expiry;
        ifstr.ignore();

        return ifstr;
    }

    int Perishable::readSku(std::istream& istr) {
        m_state.clear();
        bool success = false;
        std::cout << "SKU: ";
        while (!success) {

            if (!(istr >> m_sku)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_sku < 10000 || m_sku > 39999) {
                std::cout << "Value out of range [10000<=val<=39999]: ";
            }
            else {
                success = true;
            }
        }

        return m_sku;
    }


}















