/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.h
// Version 1.0
// Author   Fardad Soleimanloo
// Description
//   To completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
 name- patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id- 158605220
* date- 22/09/2023
***********************************************************************/
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

namespace sdds {
    struct Population {
        char postal_code[4];
        int population;
    };
   // returns true of the cstring starts with subString
   bool startsWith(const char* cString, const char* subString);
   bool getPostalCode(char* postal_code_prefix);
   bool load(const char* filename, const char* partial_postal_code_prefix);
   void display();
   void deallocateMemory();


}
#endif // SDDS_POPULATION_H_