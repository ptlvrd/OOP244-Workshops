/* Citation and Sources...
Final Project Milestone 1
Module: status
Filename: status.cpp
Version 1.0
Author	patel vundaben vijaykumar
id- 158605220
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Status.h"
#include "Utils.h"
using namespace std;
namespace sdds {
    Status::Status(const char* description)
    {
        d_code = 0;
        if (description != nullptr)
        {
            ut.alocpy(Description, description);
        }
    }
    Status::Status(const Status& stat)
    {
        if (stat.Description != nullptr)
        {
            ut.alocpy(Description, stat.Description);
            d_code = stat.d_code;
        }
        else
        {
            delete[] Description;
            Description = nullptr;
            d_code = 0;
        }
    }
    Status& Status::operator =(const char* description)
    {
        if (description != nullptr)
        {
            ut.alocpy(Description, description);
        }
        return *this;
    }
    Status& Status::operator =(int code)
    {
        d_code = code;
        return *this;

    }
    Status::operator int() const
    {
        return d_code;
    }
    Status::operator const char* () const
    {
        return Description;
    }
    Status::operator bool() const
    {
        return Description == nullptr;
    }
    Status& Status::clear()
    {
        if (Description != nullptr)
        {
            delete[] Description;
            Description = nullptr;
            d_code = 0;
        }
        return *this;
    }
    Status::~Status()
    {
        delete[] Description;
    }

    std::ostream& Status::print(std::ostream& ostr) const
    {

        if (d_code == 0)
        {
            ostr << Description;
        }
        else
        {
            ostr << "ERR#" << d_code << ": ";
            ostr << Description;
        }
        return ostr;
    }

    std::ostream& operator<<(std::ostream& os, const Status& stat)
    {
        if (stat)
        {
            //do nothing
        }
        else
        {
            stat.print(os);
        }
        return os;
    }



}




