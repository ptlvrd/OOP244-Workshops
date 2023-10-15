
/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 27/ 09 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Train.h"

using namespace std;
namespace sdds {
    Train::Train() {
        trainName = nullptr;
        passengers = -1;
        departTime = -1;
    }

    Train::~Train() {
        delete[] trainName;
    }

    void Train::initialize() {
        // Setting the name pointer to nullptr
        delete[] trainName;
        trainName = nullptr;

        // Setting other attributes to -1
        passengers = -1;
        departTime = -1;
    }

    //Returns true if the value is between the minimum and maximum acceptable values and
    //if the two right digits are less than or equal to 59.
    bool Train::validTime(int value)const {
        if (value >= MIN_TIME && value <= MAX_TIME) {
            int minutes = value % 100;
            if (minutes >= 0 && minutes <= 59) {
                return true;
            }
        }
        return false;
    }

    //Returns true if the number of passengers is positive and less than the maximum 
    //number of passengers allowed on a train.
    bool Train::validNoOfPassengers(int value)const {
        return (value > 0 && value <= MAX_NO_OF_PASSENGERS);
    }

    void Train::set(const char* name) {
        //deletes the current train name
        delete[] trainName;
        //sets the train name pointer to nullptr
        trainName = nullptr;

        //if the argument name is not nullptr and is not an empty string
        if (name && name[0] != '\0') {
            trainName = new char[strlen(name) + 1];
            strcpy(trainName, name);
        }
    }

    //sets the two attributes for the number of passengers and departure time 
    //to the incomming values if the are valid.
    void Train::set(int noOfPassengers, int departure) {
        if (validNoOfPassengers(noOfPassengers) && validTime(departure)) {
            passengers = noOfPassengers;
            departTime = departure;
        }
        else {  //if not both will be set to -1 to mark them as invalid.
            passengers = -1;
            departTime = -1;

        }
    }

    //sets the name, the number of passengers and the departure time to incomming
    //arguments using the same logic of the other two set functions.
    void Train::set(const char* name, int noOfPassengers, int departure) {
        set(name);
        set(noOfPassengers, departure);
    }

    //Finlizes the use of the Train object by deleting the memory pointed by the name attribute pointer.
    void Train::finalize() {
        delete[] trainName;
        trainName = nullptr;
    }

    //returns true if any of the attributes are set to their invalid state.
    bool Train::isInvalid()const {
        return(trainName == nullptr || passengers == -1 || departTime == -1);
    }

    //This query returns the number of people on a train.
    int Train::noOfPassengers()const {
        return passengers;

    }

    //This query returns the name of a train.
    const char* Train::getName() const {
        return trainName;

    }

    //This query returns the time of departure.
    int Train::getDepartureTime() const {
        return departTime;
    }
    
    //This member function sends the information about a Train to the standard output
    void Train::display() const {
        if (!isInvalid()) {
            cout << "NAME OF THE TRAIN :   " << trainName << endl;
            cout << "NUMBER OF PASSENGERS: " << passengers << endl;
            cout << "DEPARTURE TIME:       " << departTime << endl;
        }
        else {
            cout << "Train in an invalid State!" << endl;
        }
    }
}