/***********************************************************************
// OOP244 Workshop #5 DIY (part 2): tester program
//
// File  Portfolio.h
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
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>

namespace sdds {

   class Portfolio {
      double m_value = 0;
      char m_stock[16];
      char m_type;

   public:
       Portfolio();
       void emptyPortfolio();
       Portfolio(double value, const char* stock, char type);
       void dispPortfolio() const;
       std::ostream& display() const;
       operator double() const;
       operator const char* ()const;
       operator char()const;
       operator bool()const;
       Portfolio& operator+=(double value);
       Portfolio& operator-=(double value);
       bool operator~()const;
       Portfolio& operator<<(Portfolio& other);
       Portfolio& operator>>(Portfolio& other);

   };
   double operator + (const Portfolio& left, Portfolio& right);
   double operator +=(double& value, const Portfolio& other);
}
#endif // SDDS_Portfolio_H_