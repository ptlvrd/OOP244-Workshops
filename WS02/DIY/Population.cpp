/***********************************************************************
// OOP244 Workshop #2 DIY (part 2):
//
// File  Population.cpp
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
#include "Population.h"
#include "File.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds {
   bool startsWith(const char* cstring, const char* subString) {
      return std::strstr(cstring, subString) == cstring;
   }

   bool getPostalCode(char* postal_code_prefix) {
       cout << "Population Report\n-----------------\nEnter postal code:\n";
       cout << "> ";
       cin.getline(postal_code_prefix, 4);

       if (strcmp(postal_code_prefix, "!") == 0) {
           return false;
       }
       if (strcmp(postal_code_prefix, "all") == 0) {
           postal_code_prefix[0] = '\0'; // Set it to an empty string
       }

       return true;
   }

   Population* populations = nullptr;
   int numPopulation = 0;

   bool load(const char* filename, const char* partial_postal_code_prefix) {
       if (!openFile(filename)) {
           cout << "Error: Unable to open the file " << filename << endl;
           return false;
       }

       // Count the number of lines in the file that match the prefix
       int matches = 0;
       char line[100];
       while (read(line, sizeof(line))) {
           char postal_code[4];
           int population;
           if (sscanf(line, "%3s,%d", postal_code, &population) == 2 &&
               (strlen(partial_postal_code_prefix) == 0 || strncmp(postal_code, partial_postal_code_prefix, strlen(partial_postal_code_prefix)) == 0)) {
               matches++;
           }
       }

       // Allocate memory for matching records
       if (populations) {
           delete[] populations;
       }
       populations = new Population[matches];
       if (!populations) {
           cout << "Error: Memory allocation failed.\n";
           closeFile();
           return false;
       }

       // Reset the file to the beginning
       closeFile();
       if (!openFile(filename)) {
           cout << "Error: Unable to reopen the file " << filename << endl;
           delete[] populations;
           populations = nullptr;
           return false;
       }

       // Load matching records into the array
       int i = 0;
       while (read(line, sizeof(line))) {
           char postal_code[4];
           int population;
           if (sscanf(line, "%3s,%d", postal_code, &population) == 2 &&
               (strlen(partial_postal_code_prefix) == 0 || strncmp(postal_code, partial_postal_code_prefix, strlen(partial_postal_code_prefix)) == 0)) {
               strncpy(populations[i].postal_code, postal_code, 4);
               populations[i].population = population;
               i++;
           }
       }
       numPopulation = matches; // Update the number of records

       closeFile();
       return true;
   }


   void display() {
       std::cout << "Postal Code: population\n-------------------------\n";
       for (int i = 0; i < numPopulation - 1; i++) {
           for (int j = 0; j < numPopulation - i - 1; j++) {
               if (populations[j].population > populations[j + 1].population) {
                   // Swap elements
                   Population temp = populations[j];
                   populations[j] = populations[j + 1];
                   populations[j + 1] = temp;
               }
           }
       }
       for (int i = 0; i < numPopulation; i++) {
           cout << i + 1 << "- " << populations[i].postal_code << ":  " << populations[i].population << endl;
       }

       int total_population = 0;
       for (int i = 0; i < numPopulation; i++) {
           total_population += populations[i].population;
       }
       cout << "-------------------------\nPopulation of the listed areas: " << total_population << endl<<endl;
   }

   void deallocateMemory() {
       if (populations) {
           delete[] populations;
           populations = nullptr;
       }
       numPopulation = 0;
   }

}