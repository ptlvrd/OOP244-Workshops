/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  File.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   //to read the numebr
   bool read(int& number) {
       return fscanf(fptr, "%d", &number) == 1;
   }
   //to read the character
   bool read(char& character) {
       character = fgetc(fptr);
       return !feof(fptr);
   }
   //to read the c string
   bool read(char* str, int len) {
       return fgets(str, len, fptr) != nullptr;
   }
   //to write value
   void write(int value) {
       fprintf(fptr, "%d", value);
   }

}