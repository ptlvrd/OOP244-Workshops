/***********************************************************************

// OOP244 Workshop #2 DIY (part 2): tester program

//

// File main_prof.cpp

// Version 1.0

// Author  Fardad Soleimanloo

// Description

//

// Revision History

// -----------------------------------------------------------

// Name      Date      Reason
 name- patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id- 158605220
* date- 22/09/2023

***********************************************************************/

#include <iostream>
#include "file.h"
#include "Population.h"

using namespace sdds;

int main() {

    char code[4]{};

    while (getPostalCode(code)) {

        if (load("PCpopulationsComplete.csv", code)) {

            display();

        }

        deallocateMemory();

    }

    return 0;

}

