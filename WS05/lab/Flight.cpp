/***********************************************************************
// OOP244 Workshop #5 lab (part 1): tester program
//
// File  Flight.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title , "EmptyPlane");
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title,title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char *)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

   // Returns true if the Flight number of passengers is greater than 0, and the amount of fuel in the plane's tank is equal to 
  //or greater than the minimum required to carry the number of passengers currently on the plane. otherwise false. This operator can not modify the Flight object.
    Flight::operator bool() const {
        return ((m_passengers > 0) && (m_fuel >= 600 * m_passengers));
    }

    //Returns the Flight number of passengers. 
    Flight::operator int() const {
        return m_passengers;
    }

    //Returns the Flight Fuel
    Flight::operator double() const {
        return m_fuel;
    }

    //returns the Fligt title 
    Flight::operator const char* () const {
        return m_title;
    }

    //This operator returns true if the Flight number of passengers is equal to 0
    bool Flight::operator~() const {
        return m_passengers == 0;
    }

    //overload the assignment operator so a Flight can be set to another Flight object.
    Flight& Flight::operator=( Flight& other) {
            strcpy(m_title, other.m_title);
            m_fuel = other.m_fuel;
            m_passengers = other.m_passengers;
            other.emptyPlane();
            return *this;
    }

    //Overload the assignment operator so a Flight can be set to an integer. 
    Flight& Flight::operator=(int other) {
        if (other > 0 && other <= Boen747Capacity) {
            m_passengers = other;
        }
        return *this;
    }

    //Overload the assignment operator so a Flight can be set to a double
    Flight& Flight::operator=(double other) {
        if (other > 0 && other < FuelTankCapacity) {
            m_fuel = other;
        }
        return *this;
    }

    //Overload the += operator to add a double value to a Flight.
    Flight& Flight::operator+=(double other) {
        if (other > 0 && m_fuel < FuelTankCapacity) {
            m_fuel += other;
        }
        return *this;
    }

    //Overload the += operator to add an integer value to a Flight.
    Flight& Flight::operator+=(int other) {
        if (other > 0 && m_passengers < Boen747Capacity) {
            m_passengers += other;
        }
        return *this;
    }

    //overload the -= operator to reduce a Flight fuel by a double value
    Flight& Flight::operator-=(double other) {
        if (other > 0 && m_fuel > 0) {
            m_fuel -= other;
        }
        return *this;
    }

    //Overload the -= operator to reduce the number of passengers in a Flight fuel by an integer value. 
    Flight& Flight::operator-=(int other) {
        if (other > 0 && m_passengers > 0) {
            m_passengers -= other;
        }
        return *this;
    }

    //Overload the << operator* (left shift operator) to move passengers from the right Flight to the left
    Flight& Flight::operator<<(Flight& other) {
        if (*this && other) {
            int totalPassengers = m_passengers + other.m_passengers;
            if (totalPassengers <= Boen747Capacity) {
                m_passengers = totalPassengers;
                other.m_passengers = 0;
            }
            else if (totalPassengers > Boen747Capacity) {
                m_passengers = Boen747Capacity;
                other.m_passengers = totalPassengers - Boen747Capacity;
            }
        }
        return *this;
    }

    //Overload the >> operator (right shift operator) to move passengers from the left Flight to the right.
    Flight& Flight::operator>>(Flight& other) {
        other << *this;
        return *this;
    }

    //Overload the binary member + operator that accepts a constant Flight reference and returns a int value.
    int Flight::operator+(const Flight& other) {
        if (*this && other) {
            return (int)*this + (int)other;
        }
        return 0;
    }

    //a binary stand alone helper += operator that accepts an int reference at left and a constant Flight reference at right and returns an int value.
    int operator+=(int& a, const Flight& other) {
        a += (int)other;
        return a;
    }

}