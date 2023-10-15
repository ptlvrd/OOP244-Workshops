
/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 29/ 09 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H
#define MIN_TIME 700
#define MAX_TIME 2300
#define MAX_NO_OF_PASSENGERS 1000

namespace sdds {
	class Train {
	private:
		char* trainName;
		int passengers;
		int departTime;

		bool validTime(int value) const;
		bool validNoOfPassengers(int value) const;
		bool validName(const char* name) const;
	public:
		void initialize();
		void set(const char* name);
		void set(int noOfPassengers, int departure);
		void set(const char* name, int noOfPassengers, int departure);
		void finalize();
		bool isInvalid() const;
		int noOfPassengers() const;
		const char* getName() const;
		int getDepartureTime() const;
		void display() const;

		//DIY function
		bool load(int& notBoarded);
		bool updateDepartureTime();
		bool transfer(const Train& otherTrain);

	};
}

#endif // SDDS_TRAIN_H
