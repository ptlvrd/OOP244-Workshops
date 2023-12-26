/*Author	patel vundaben vijaykumar
id - 158605220
date 12-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include <sstream>
#include <string>

using namespace std;

namespace sdds {

    Menu::Menu(const char* content) : menuContent(nullptr), numOptions(0) {
       setContent(content);
    }

    void Menu::setContent(const char* content) {
        if (content != nullptr) {
            numOptions = 0;
            for (int i = 0; content[i] != '\0'; i++) {
                if (content[i] == '\t') {
                    numOptions++;
                }
            }
            if (numOptions > 15) {
                cout << "Invalid Menu!" << endl;
                return;
            }
            delete[] menuContent;
            menuContent = new char[strlen(content) + 1];
            strcpy(menuContent, content);
        }
    }

    Menu::~Menu() {
        delete[] menuContent;
    }


    unsigned int Menu::run() {
        if (menuContent == nullptr) {
            //cout << "Invalid Menu!";
            return 0;
        }

        int optionNumber = 1;
        cout << "---------------------------------" << endl;
        cout << optionNumber << "- ";
        for (int i = 0; menuContent[i] != '\0'; i++) {
            if (menuContent[i] == '\t') {
                optionNumber++;
                cout << endl << optionNumber << "- ";
            }
            else {
                cout << menuContent[i];
            }
        }

        numOptions = optionNumber;

        cout << endl;
        for (int i = 0; i < 33; i++) {
            cout << "-";
        }
        cout << endl;

        cout << "0- Exit" << endl;

        int choice;
        cout << "> ";
        do {
            if (!(cin >> choice)) {
                cout << "Invalid Integer, retry: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else if (choice < 0 || choice > numOptions) {
                cout << "Value out of range [0<=val<=" << numOptions << "]: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else {
                break;
            }
        } while (true);

        return choice;
    }




}