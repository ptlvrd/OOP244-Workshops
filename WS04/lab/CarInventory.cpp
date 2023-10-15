/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 06/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "CarInventory.h"
#include<iomanip>
#include <cstdio>

using namespace std;
namespace sdds {

    CarInventory::CarInventory() {
        resetInfo();
    }
    CarInventory::CarInventory(const char* type, const char* brand, const char* model, int year, int code, double price) {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        resetInfo();

        if (type && brand && model) {
            m_type = new char[strlen(type) + 1];
            m_brand = new char[strlen(brand) + 1];
            m_model = new char[strlen(model) + 1];
            strcpy(m_type, type);
            strcpy(m_brand, brand);
            strcpy(m_model, model);
        }

        if (year >= 1990) {
            m_year = year;
        }
        else {
            m_year = 2022; 
        }

        if (code >= 100 && code <= 999) {
            m_code = code;
        }
        else {
            m_code = 100; 
        }

        if (price > 0) {
            m_price = price;
        }
        else {
            m_price = 1.0; 
        }
    }


    void CarInventory::resetInfo() {
        m_type = nullptr;
        m_brand = nullptr;
        m_model = nullptr;
        m_year = 0;
        m_code = 0;
        m_price = 0;
    }

    CarInventory& CarInventory::setInfo(const char* type, const char* brand, const char* model, int year = 2022, int code = 100, double price = 1.0) {
        delete[] this->m_type;
        delete[] this->m_brand;
        delete[] this->m_model;
        resetInfo();

        this->m_type = new char[strlen(type) + 1];
        strcpy(this->m_type, type);

        this->m_brand = new char[strlen(brand) + 1];
        strcpy(this->m_brand, brand);

        this->m_model = new char[strlen(model) + 1];
        strcpy(this->m_model, model);

        this->m_year = year;
        this->m_code = code;
        this->m_price = price;
        if (!isValid()) {
            delete[] this->m_type;
            delete[] this->m_brand;
            delete[] this->m_model;
            resetInfo();
        }
        return *this;
    }
    void CarInventory::printInfo() const {
        cout << "| " << setw(10) << left << m_type

            << " | " << setw(16) << left << m_brand

            << " | " << setw(16) << left << m_model

            << " | " << setw(4) << m_year

            << " |  " << setw(3) << m_code

            << " |" << setw(10) << right << fixed << setprecision(2) << m_price << " |" << endl;
    }

    bool CarInventory::isValid() const {
        bool ok = true;
        if (m_type == nullptr || m_brand == nullptr || m_model == nullptr || m_year < 1990 || (m_code < 100 && m_code > 999) || m_price <= 0) {
            ok = false;
        }
        return ok;

    }

    bool CarInventory::isSimilarTo(const CarInventory& car) const {
        bool ok = false;
        if ((m_type && strcmp(car.m_type, m_type) == 0) && (m_brand && strcmp(car.m_brand, m_brand) == 0) && (m_model && strcmp(car.m_model, m_model) == 0) && (car.m_year == m_year)) {
            ok = true;
        }
        return ok;
    }

    CarInventory::~CarInventory() {
        delete[] m_type;
        delete[] m_brand;
        delete[] m_model;
    }

    int find_similar(CarInventory car[], const int num_cars) {
        for (int i = 0; i < num_cars; i++) {
            for (int j = i + 1; j < num_cars; j++) {
                if (car[i].isSimilarTo(car[j])) {
                    return i;
                }
            }
        }
        return -1;
    }
}
