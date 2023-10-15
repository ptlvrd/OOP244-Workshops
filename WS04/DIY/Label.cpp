/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 07/ 10 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Label.h"
using namespace std;
namespace sdds {

    //Creates an empty label and defaults the frame to "+-+|+-+|"
    Label::Label() {
        const char defaultFrame[] = "+-+|+-+|";
        std::memcpy(frame, defaultFrame, sizeof(frame));
        labelContent = nullptr;
    }

    //Creates an empty label and sets the frame to the frameArg argument. If the frameArg
    //is nullptr, the default frame will be used instead.
    Label::Label(const char* frameArg) {
        const char defaultFrame[] = "+-+|+-+|";
        if (frameArg != nullptr) {
            strcpy(frame, frameArg);
        }
        else {
            strcpy(frame, defaultFrame);
        }
        labelContent = nullptr;
    }

    //Creates a Label with the frame set to frameArg and the content of the Label set to the
    //corresponding argument.Note that you must keep the content dynamically even though it
    //should never be more than 70 characters.
    Label::Label(const char* frameArg, const char* content) {
        const char defaultFrame[] = "+-+|+-+|";
        if (frameArg != nullptr) {
            strcpy(frame, frameArg);
        }
        else {
            strcpy(frame, defaultFrame);
        }
        labelContent = nullptr;
        if (content != nullptr) {
            labelContent = new char[MAX_CONTENT_CHAR + 1];
            strncpy(labelContent, content, MAX_CONTENT_CHAR);
            labelContent[MAX_CONTENT_CHAR] = '\0';
        }

    }

    //destructor
    Label::~Label() 
    {
        delete[] labelContent;
    }

    //Reads the content of the label from the console up to 70 characters and stores 
    //it in the Label as shown below and then returns the cin.
    istream& Label::readLabel(std::istream& ist) {
        char content[71];
        ist.get(content, 71);
        ist.ignore(10000, '\n');
        text(content);
        return ist;
    }

    //Prints the label by drawing the frame around the content as shown below. Note that
    //no newline is printed after the last line and cout is returned at the end.
    std::ostream& Label::printLabel(std::ostream& ostr) const {
        if (labelContent != nullptr) {
            ostr << frame[0] << std::setw((strlen(labelContent) + 3)) << std::setfill(frame[1]) << frame[2] << std::endl;
            ostr << frame[7] << std::setw((strlen(labelContent) + 3)) << std::setfill(' ') << frame[3] << std::endl;
            ostr << frame[7] << " " << labelContent << " " << frame[3] << std::endl;
            ostr << frame[7] << std::setw((strlen(labelContent) + 3)) << std::setfill(' ') << frame[3] << std::endl;
            ostr << frame[6] << std::setw((strlen(labelContent) + 3)) << std::setfill(frame[5]) << frame[4];
        }
        return ostr;
    }

    Label& Label::text(const char* content) {
        if (labelContent != nullptr) {
            delete[] labelContent;
            labelContent = nullptr;
        }

        labelContent = new char[MAX_CONTENT_CHAR + 1];
        strncpy(labelContent, content, MAX_CONTENT_CHAR);
        labelContent[MAX_CONTENT_CHAR] = '\0';

        return *this;
    }




}