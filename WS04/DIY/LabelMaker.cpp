/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 07/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "LabelMaker.h"
using namespace std;
namespace sdds {
    //creates a dynamic array of Labels to the size of noOfLabels
	LabelMaker::LabelMaker(int noOfLabels) : noOfLabels(noOfLabels) {
		labels = new Label[noOfLabels];
	}

    //Gets the contents of the Labels as demonstrated below (Assuming there are two labels in the LabelMaker):
    void LabelMaker::readLabels() {
        cout << "Enter " << noOfLabels << " labels:" << endl;
        for (int i = 0; i < noOfLabels; i++) {
            cout << "Enter label number " << i + 1 << endl;
            cout << "> ";
            char content[71]; 
            std::cin.getline(content, sizeof(content));
            labels[i].text(content);
        }
    }

    //printing labels
    void LabelMaker::printLabels() {
        int i = 0;
        for (i = 0; i < noOfLabels; i++) {
            labels[i].printLabel() << endl;
        }

    }

    LabelMaker::~LabelMaker() {
        delete[] labels; 
    }


}