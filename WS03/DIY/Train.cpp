/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 29/ 09 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "Train.h"


using namespace std;
namespace sdds {

   
    void Train::initialize() {
        // Setting the name pointer to nullptr
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
        if (validName(name)) {
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

    bool Train::validName(const char* name) const {
        return (name != nullptr && name[0] != '\0');
    }

    //Finlizes the use of the Train object by deleting the memory pointed by the name attribute pointer.
    void Train::finalize() {
        delete[] trainName;
        trainName = nullptr;
    }

    //returns true if any of the attributes are set to their invalid state.
    bool Train::isInvalid()const {
        return validTime(departTime) && validNoOfPassengers(passengers) && validName(trainName) ? false : true;
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
            cout << "NAME OF THE TRAIN:    " << trainName << endl;
            cout << "NUMBER OF PASSENGERS: " << passengers << endl;
            cout << "DEPARTURE TIME:       " << departTime << endl;
        }
        else {
            cout << "Train in an invalid State!" << endl;
        }
    }

    //DIY part
    bool Train::load(int& notBoarded) {
        //it will ask the user for the number of passengers and then try to board them all
        cout << "Enter number of passengers boarding :" << endl << "> ";
        unsigned int passengers2{};
        bool boarded = false;
        cin >> passengers2;
        this->passengers += passengers2;


        //f the total number of passengers is more than the maximum number of people allowed on the trai
        if (validNoOfPassengers(passengers)) { //The function returns true if everyone is boarded and false if some are left behind
            boarded = true;
            notBoarded = 0;
        }
        else {
            notBoarded = passengers - MAX_NO_OF_PASSENGERS;
            passengers = MAX_NO_OF_PASSENGERS;

        }
        return boarded;
    }

    //Updates the departure time of a train.
    bool Train::updateDepartureTime() {
        cout << "Enter new departure time:" << endl << "> ";
        unsigned int newDepartTime{};
        bool is_time = false;
        cin >> newDepartTime;
        if (validTime(newDepartTime)) {
            //if the value was a valid time value it will reset the departure time to the new value
            departTime = newDepartTime;
            is_time= true;
        }
        else {
            //f the value is not valid, it will set the departure time to -1.
            departTime = -1;
        }
        return is_time;
    }

    //transfers the passengers of a Train to the current Train.
    bool Train::transfer(const Train& otherTrain) {
        bool transfer = false;

        // This function's execution is considered successful if both the current Train 
        // and the Train referenced by the argument are in a valid state.
        if (!this->isInvalid() && !otherTrain.isInvalid()) {


            // The transfer function will first change the name of the current Train to a combination 
            // of the names of the two trains.
            size_t combinedLength = strlen(this->trainName) + strlen(", ") + strlen(otherTrain.trainName) + 1;
            char* newTrainName = new char[combinedLength];
            if (newTrainName != nullptr) {
                strcpy(newTrainName, this->trainName);
                strcat(newTrainName, ", ");
                strcat(newTrainName, otherTrain.trainName);
                delete[] this->trainName;
                this->trainName = newTrainName;
                this->passengers += otherTrain.passengers;
                if (validNoOfPassengers(this->passengers)) {
                    transfer = true;
                }
                else {
                    cout << "Train is full; " << this->passengers - MAX_NO_OF_PASSENGERS << " passengers of " << otherTrain.trainName << " could not be boarded!" << endl;
                    this->passengers = MAX_NO_OF_PASSENGERS;
                    transfer = true;
                }
            }
            else {
                cout << "Memory allocation failed for the new name." << endl;
            }
        }

        return transfer;
    }


}