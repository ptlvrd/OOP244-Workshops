/*Author	patel vrundaben vijaykumar
id - 158605220
date 29-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include "Item.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <string>
#include <limits>


namespace sdds {

    Item::Item() : m_price(0.0), m_qty(0), m_qtyNeeded(0), m_description(nullptr), m_linear(false), m_sku(0) {}

    Item::~Item() {
        delete[] m_description;
    }

    Item::Item(const Item& src) : m_price(src.m_price), m_qty(src.m_qty), m_qtyNeeded(src.m_qtyNeeded),
        m_linear(src.m_linear), m_state(src.m_state), m_sku(src.m_sku) {
        if (src.m_description != nullptr) {
            m_description = new char[strlen(src.m_description) + 1];
            strcpy(m_description, src.m_description);
        }
        else {
            m_description = nullptr;
        }
    }

    Item& Item::operator=(const Item& src) {
        if (this != &src) {
            m_price = src.m_price;
            m_qty = src.m_qty;
            m_qtyNeeded = src.m_qtyNeeded;
            m_linear = src.m_linear;
            m_state = src.m_state;
            m_sku = src.m_sku;

            delete[] m_description;

            if (src.m_description != nullptr) {
                m_description = new char[strlen(src.m_description) + 1];
                strcpy(m_description, src.m_description);
            }
            else {
                m_description = nullptr;
            }
        }
        return *this;
    }

    void Item::clear() {
        m_state.clear();
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

    Item::operator bool() const {
        return m_state;
    }

    int Item::operator-=(int qty) {
        if (qty > 0) {
            m_qty -= qty;
        }
        return m_qty;
    }

    int Item::operator+=(int qty) {
        if (qty > 0) {
            m_qty += qty;
        }
        return m_qty;
    }

    void Item::linear(bool isLinear) {
        m_linear = isLinear;
    }

    bool Item::operator==(int sku) const {
        return m_sku == sku;
    }

    bool Item::operator==(const char* description) const {
        if (description == nullptr || m_description == nullptr) {
            return false;
        }

        if (isdigit(description[0]) && std::stoi(description) == m_sku) {
            return true;
        }

        if (strstr(m_description, description) != nullptr) {
            return true;
        }

        return false;
    }

    std::ofstream& Item::save(std::ofstream& ofstr) const {
        if (m_state) {
            ofstr << m_sku << "\t" << m_description << "\t" << m_qty << "\t" << m_qtyNeeded << "\t"
                << std::fixed << std::setprecision(2) << m_price << "\t";
        }
        return ofstr;
    }

    std::ifstream& Item::load(std::ifstream& ifstr) {
        delete[] m_description;

        m_description = nullptr;
        ifstr >> m_sku;
        if (ifstr.fail()) {
            m_state = "Input file stream read failed!";
        }
        else {

            char temp[2000];
            ifstr.ignore();
            ifstr.getline(temp, 2000, '\t');
            m_description = new char[strlen(temp) + 1];
            strcpy(m_description, temp);

            ifstr >> m_qty;
            ifstr.ignore();

            ifstr >> m_qtyNeeded;
            ifstr.ignore();

            ifstr >> m_price;
            ifstr.ignore();
        }
        return ifstr;
    }

    std::ostream& Item::display(std::ostream& ostr) const {
        if (!m_state) {
            ostr << m_state;
        }
        if (m_state && m_sku != 0 && m_description != nullptr) {
            if (m_linear) {
                ostr << std::setw(5) << m_sku << " | "
                    << std::left << std::setw(35) << std::setfill(' ') << (std::strlen(m_description) > 35 ? std::string(m_description, 35) : m_description)
                    << " | " << std::right << std::setw(4) << m_qty << " | "
                    << std::right << std::setw(4) << m_qtyNeeded << " | "
                    << std::right << std::setw(7) << std::setprecision(2) << m_price << " |";
            }
            else {
                ostr << "AMA Item:" << std::endl
                    << std::setw(5) << m_sku << ": "
                    << m_description << std::endl
                    << std::setw(6) << "Quantity Needed: " << m_qtyNeeded << std::endl
                    << std::setw(6) << "Quantity Available: " << m_qty << std::endl
                    << std::setw(6) << "Unit Price: $" << std::fixed << std::setprecision(2) << m_price << std::endl
                    << std::setw(6) << "Needed Purchase Fund: $" << std::fixed << std::setprecision(2) << (m_qtyNeeded * m_price) - (m_qty * m_price) << std::endl;
            }
        }
        return ostr;
    }

    int Item::readSku(std::istream& istr) {
        m_state.clear();
        bool success = false;
        std::cout << "SKU: ";
        while (!success) {

            if (!(istr >> m_sku)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_sku < 40000 || m_sku > 99999) {
                std::cout << "Value out of range [40000<=val<=99999]: ";
            }
            else {
                success = true;
            }
        }

        return m_sku;
    }

    std::istream& Item::read(std::istream& istr) {
        delete[] m_description;
        m_description = nullptr;

        std::cout << "AMA Item:" << std::endl
            << "SKU: " << m_sku << std::endl
            << "Description: ";

        istr.ignore();
        char temp[2000];
        istr.getline(temp, 2000);
        m_description = new char[strlen(temp) + 1];
        strcpy(m_description, temp);

        bool success = false;
        std::cout << "Quantity Needed: ";
        while (!success) {

            if (!(istr >> m_qtyNeeded)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_qtyNeeded < 1 || m_qtyNeeded > 9999) {
                std::cout << "Value out of range [1<=val<=9999]: ";
            }
            else {
                success = true;
            }
        }

        success = false;
        std::cout << "Quantity On Hand: ";
        while (!success) {

            if (!(istr >> m_qty)) {
                std::cout << "Invalid Integer, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_qty < 0 || m_qty > m_qtyNeeded) {
                std::cout << "Value out of range [0<=val<=22]: ";
            }
            else {
                success = true;
            }
        }

        success = false;
        std::cout << "Unit Price: $";
        while (!success) {

            if (!(istr >> m_price)) {
                std::cout << "Invalid number, retry: ";
                istr.clear();
                istr.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else if (m_price < 0.0 || m_price > 9999.0) {
                std::cout << "Value out of range [0.00<=val<=9999.00]: ";
            }
            else {
                success = true;
            }
        }

        return istr;
    }


    bool Item::linear() const {
        return m_linear;
    }
}

















