/*Author	patel vundaben vijaykumar
id - 158605220
date 12-11-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "AidMan.h"
#include "Menu.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <limits>
#include "Utils.h"

using namespace std;
namespace sdds {

    AidMan::AidMan():fileName(nullptr), mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),
        numProducts(0) {
        for (int i = 0; i < sdds_max_num_items; ++i) {
            products[i] = nullptr;
        }
        if (fileName != nullptr)
            ut.alocpy(fileName, fileName);
        else
            delete[] fileName;
        fileName = nullptr;
    }
    AidMan::AidMan(const char* filename) : fileName(nullptr), mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database"),
        numProducts(0) {
       /* for (int i = 0; i < sdds_max_num_items; ++i) {
            products[i] = nullptr; // Initialize each element in the products array
        }*/
        if (filename != nullptr) {
            fileName = new char[strlen(filename) + 1];
            strcpy(fileName, filename);
        }
    }


    AidMan::~AidMan() {
      deallocate();
    }
    void AidMan::save() const {
        if (fileName != nullptr) {
            ofstream ofstr(fileName, ios::out);
            for (int i = 0; i < numProducts; i++) {
                products[i]->save(ofstr);
              
                ofstr << endl;
            }
            ofstr.close();
        }
    }
    void AidMan::run() {
        unsigned int choice;

        do {
            choice = menu();

            if (choice != 0 && choice != 7 && fileName == nullptr) {
                choice = 7;
                cout << "\n****New/Open Aid Database****\n";
                cout << "Enter file name: ";
                char filename[256];
                cin >> filename;

                if (load(filename)) {
                    //cout << numProducts << " records loaded!\n";
                    fileName = new char[strlen(filename) + 1];
                    strcpy(fileName, filename);
                }
                else {
                    cout << "Failed to load records.\n";
                }
            }
            else {
                switch (choice) {
                case 0:
                    cout << "Exiting Program!\n";
                    break;
                case 1:
                    cout << "\n****List Items****\n";
                    list();
                    break;
                case 2:
                    cout << "\n****Add Item****\n\n";
                    break;
                case 3:
                    cout << "\n****Remove Item****\n\n";
                    break;
                case 4:
                    cout << "\n****Update Quantity****\n\n";
                    break;
                case 5:
                    cout << "\n****Sort****\n\n";
                    break;
                case 6:
                    cout << "\n****Ship Items****\n\n";
                    break;
                case 7:
                    cout << "\n****New/Open Aid Database****\n\n";
                    break;
                }
            }
        } while (choice != 0);
        save();
    }

    void AidMan::deallocate() {
        for (int i = 0; i < numProducts; i++) {
            delete products[i];
        }
        delete[] fileName;
        numProducts = 0;
    }

    bool AidMan::load(const char* filename) {
        numProducts = 0;
        save();
        deallocate();

        ifstream ifstr(filename);
        if (!ifstr.is_open()) {
            cout << "Failed to open " << filename << " for reading!" << endl;
            return false;
        }

        int i = 0;
        while (i < sdds_max_num_items && ifstr >> ws && !ifstr.eof()) {
            char nextChar = ifstr.peek();
            if (nextChar == '1' || nextChar == '2' || nextChar == '3') {
                products[i] = new Perishable;
            }
            else if (nextChar >= '4' && nextChar <= '9') {
                products[i] = new Item;
            }
            else {
                delete products[i];
                ifstr.ignore(1000, '\n');
                continue;
            }

            products[i]->load(ifstr);
            i++;
        }

        numProducts = i;

        if (numProducts > 0) {
            cout << numProducts << " records loaded!" << endl<<endl;
        }

        return true;
    }


    //menuitem1
    int AidMan::list(const char* sub_desc){
        cout << fixed << setprecision(2);
        if (numProducts == 0) {
            cout << "The list is empty!" << endl;
        }
        int i = 0;
        if (sub_desc == nullptr) {
            cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;


            for (int i = 0; i < numProducts; i++) {
                cout.setf(ios::right);
                cout.width(4);
                cout << i + 1;
                cout << " | ";
                cout.unsetf(ios::right);
                products[i]->linear(true);
                products[i]->display(cout) << endl;
            }

            cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            cout << "Enter row number to display details or <ENTER> to continue:" << endl;
            cout << "> ";
            string input;
            cin.ignore();
            getline(cin, input);

            if (input.empty()) {
                //if the input is empty (user pressed Enter), do nothing and continue
                cout << endl;
                return i;
            }

            stringstream ss(input);
            int idx;
            if (!(ss >> idx) || idx < 1 || idx > numProducts || input.length() != ss.str().length()) {
            
               // cout << "Invalid input. Please enter a valid row number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else {
                
                products[idx - 1]->linear(false);
                products[idx - 1]->display(cout);
                cout << endl;
            }
        }
        else {
            cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl
                << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
            for (i = 0; i < numProducts; i++) {
                if (*products[i] == sub_desc)
                {
                    cout.setf(ios::right);
                    cout.width(4);
                    cout << i + 1;
                    cout << " | ";
                    cout.unsetf(ios::right);
                    products[i]->linear(true);
                    products[i]->display(cout);
                    cout << endl;
                }

                cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;

            }

        }return i;

    }
    unsigned int AidMan::menu() {
        cout << "Aid Management System" << endl;

        cout << "Date: ";
        Date().print(cout);
        cout << endl;

        cout << "Data file: " << (fileName != nullptr ? fileName : "No file") << endl;
       //cout << "---------------------------------" << endl;

        return mainMenu.run(); 
    }



}
