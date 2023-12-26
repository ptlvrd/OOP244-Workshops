/* Citation and Sources...
Final Project Milestone 1
Module: status
Filename: status.h
Version 1.0
Author	patel vundaben vijaykumar
id- 158605220
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
-----------------------------------------------------------*/

#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
#include<cstring>
namespace sdds {
    class Status
    {
        char* Description{};
        int d_code;
    public:
        Status(const char* description = nullptr);
        Status(const Status& stat);
        Status& operator =(const char* description);
        Status& operator =(int code);
        operator int() const;
        operator const char* () const;
        operator bool() const;
        Status& clear();
        std::ostream& print(std::ostream& ostr) const;
        ~Status();

    };
    std::ostream& operator<<(std::ostream& os, const Status& stat);

}
#endif
