/*Author	patel vrundaben vijaykumar
id - 158605220
date 04-12-2023
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.*/
#ifndef SDDS_SELECTION_H
#define SDDS_SELECTION_H
#include<cstddef>
#include<iostream>

using namespace std;

namespace sdds {
	template<typename arrayType, typename keyType>
	int* select(const arrayType array[], const keyType& key, size_t size)
	{
		size_t count = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == key) {
				count++;
			}
		}

		int* indices = new int[count + 1];

		size_t index = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] == key) {
				indices[index] = static_cast<int>(i);
				index++;
			}
		}
		indices[count] = -1;

		return indices;
	}

	template<typename arrayType>
	void csvDisplaySelection(const char* title, const arrayType array[], const int* indices)
	{
		std::cout << title << endl;

		if (indices == nullptr || indices[0] == -1) {
			std::cout << "Empty Selection" << std::endl;
			return;
		}

		for (int i = 0; indices[i] != -1; i++) {
			std::cout << array[indices[i]];

			if (indices[i + 1] != -1) {
				std::cout << ", ";
			}
		}

		std::cout << std::endl;
	}
}
#endif // !SDDS_SELECTION_H