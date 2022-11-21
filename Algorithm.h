#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "dataHandling.h"

class Algorithm {
public:
	//constructor
	Algorithm();
	Algorithm(Data mat, Data por);

	//algorithm functions
	void algorithm1();
	void algorithm2();
	void algorithm3();

	//math functions
	double avg(std::vector<int> vec, int beg, int end);
	std::vector<int> frequency(std::vector<int> vec, unsigned int set, int nonZero);

	//print functions
	void printFrequency(std::vector<int> frequency, int course);

	template<typename T> void printVect(std::vector<T> vec, int num) {
		int i = 0;
		for (T item : vec) {
			if (i > num) {
				std::cout << "\n";
				i = 0;
			}
			std::cout << std::left << std::setw(3) << item << " ";
			i++;
		}
		std::cout << "\n";
	}

private:
	Data mat;
	Data por;
};

#endif // !ALGORITHM_H
