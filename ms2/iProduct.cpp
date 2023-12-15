/*Author	patel vrundaben vijaykumar
id - 158605220
date 22-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "iProduct.h"

namespace sdds {
    std::istream& operator>>(std::istream& istr, iProduct& iproduct) {
        iproduct.read(istr);
        return istr;
    }

    std::ostream& operator<<(std::ostream& ostr, const iProduct& iproduct) {
        iproduct.display(ostr);
        return ostr;
    }
}
