/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.cpp
// Version 1.0
// Author   Asam Gulaid, revised by Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name                 Date            Reason
name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 14/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "Portfolio.h"
#include<iostream>
#include<cstring>

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
       emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && ( type == 'V' || type == 'G' || type == 'I') ) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const{
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Value: ";
            cout.width(10);
            cout << double(*this);
            cout << " | ";
            cout << " Type: ";
            cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    //Portfolio can be casted to a double (double type). The result would be the value of 
    // the Portfolio m_value. This operator can not modify the Portfolio object.
    Portfolio::operator double() const {
        return m_value;
    }

    //Portfolio can be casted to C-string (const char* type). The result would be the
    //name of the stock m_stock. This operator can not modify the Portfolio object.
    Portfolio::operator const char* ()const {
        return m_stock;
    }

    //Portfolio can be casted to a char (char type). The result would be the type of
    //investment m_type. This operator can not modify the Portfolio object.
    Portfolio::operator char() const {
        return m_type;
    }
 
    //Portfolio can be casted to a bool (boolean type). This will return TRUE if the type of the investment m_type is 
    //Growth 'G' or Value 'V or Investment 'I'. For any other types, it will return FALSE.
    Portfolio::operator bool() const {
        return m_type == 'G' || m_type == 'V' || m_type == 'I';
    }

    //A double can be added to the value of the Portfolio m_value using += operator; if the Portfolio does not evaluate
    // TRUE or the double value is negative, the action is omitted. Reference of the Portfolio is returned after the operation.
    Portfolio& Portfolio::operator+=(double value) {
        if (*this && value > 0) {
            m_value += value;
        }
        return *this;
    }
    
    //A double can be subtracted from the value of the Portfolio m_value using -= operator; if the Portfolio does not evaluate 
    //TRUE or the double value is negative, the action is omitted. Reference of the Portfolio is returned after the operation.
    Portfolio& Portfolio::operator-=(double value) {
        if (*this && value > 0) {
            m_value -= value;
        }
        return *this;
    }

    //The bool operator ~() will return true if m_value is negative. This operator can not modify the Portfolio object.
    bool Portfolio::operator~()const {
        return m_value < 0;
    }

    //verload the << operator* (left shift operator) to move $dollar investment value m_value from Portfolio in the right to the left. Afte
    //this operation, the total investment value of the Portfolio on the left will be the sum of both Portfolios. The Portfolio on the right is set to empty.
    Portfolio& Portfolio::operator<<(Portfolio& other) {
        if (*this && other) {
            m_value += other.m_value;
            other.emptyPortfolio();
        }
        return *this;
    }

    //overload the >> operator* (right shift operator) to move $dollar investment value m_value from Portfolio in the left to the right. After
    //this operation, the total investment value of the Portfolio in the right will be the sum of both Portfolios. The Portfolio on the left is set to empty.
    Portfolio& Portfolio::operator>>(Portfolio& other) {

        other << *this;
        return *this;
    }

    // a binary stand alone helper + operator that accepts a constant Portfolio reference at left and another constant Portfolio reference 
    //at right and returns a double value.
    double operator+(const Portfolio& left, Portfolio& right) {
        double value = 0;
        if (left && right) {
            value = (double)left + (double)right;
        }
        return value;
    }

    //a binary stand alone helper += operator that accepts a double reference at 
    // left and a constant Portfolio reference at right and returns a double value.
    double operator +=(double& value, const Portfolio& other)
    {
        value += double(other);
        return value;
    }


}