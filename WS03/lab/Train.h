
/*name - patel vrundaben vijaykumar
* email - vvpatel20@myseneca.ca
* seneca id - 158605220
* date - 27/ 09 / 2023
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_TRAIN_H
#define SDDS_TRAIN_H

namespace sdds {
	class Train {
	private:
		char* trainName;
		int passengers;
		int departTime;

		bool validTime(int value) const;
		bool validNoOfPassengers(int value) const;

	public:
		static const int MIN_TIME = 700;
		static const int MAX_TIME = 2300;
		static const int MAX_NO_OF_PASSENGERS = 1000;
		//constructor
		Train();
		~Train(); 

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

	};
}

#endif // SDDS_TRAIN_H