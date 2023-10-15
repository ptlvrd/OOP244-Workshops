/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.h
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
* date - 12/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

***********************************************************************/
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

   const int Boen747Capacity = 388;
   const int FuelTankCapacity = 238840;

   class Flight {

      int m_passengers = 0;
      double m_fuel = 0;
      char m_title[16];
      void emptyPlane();

   public:
      Flight();
      Flight(int passengers, double fuel, const char* title);
      std::ostream& display()const;

      //to be implemented
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char* () const;
      bool operator~() const;
      // Assignment Operators
      Flight& operator =(Flight& other);
      Flight& operator=(int other);
      Flight& operator=(double other);
      Flight& operator+=(double other);
      Flight& operator+=(int other);
      Flight& operator-=(double other);
      Flight& operator-=(int other);
      Flight& operator<<(Flight& other);
      Flight& operator>>(Flight& other);
      int operator+(const Flight& other);
   };
   int operator+=(int& a, const Flight& other);


}
#endif // SDDS_FLIGHT_H