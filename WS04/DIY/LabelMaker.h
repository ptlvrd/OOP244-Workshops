/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 07/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LABEL_MAKER_H
#define SDDS_LABEL_MAKER_H
#include "Label.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds {
    class LabelMaker {
    private:
        Label* labels;
        int noOfLabels;

    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}
#endif // !SDDS_LABEL_MAKER_H