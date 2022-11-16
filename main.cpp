#include "dataHandling.h"

template<typename T> void printVect(std::vector<T> vec, int num);

int main()
{
    using namespace std;

    //sample of how to use Data class
    Data mat("student-mat.csv");

	//sample how to use sort and print functions
	//printing top 20 and bottom 20 data
	mat.printDataPartial(20, 20);
	//targetting specifically absences vector
    vector<int> vec = mat.getAbsences();
    mat.sort(vec, 0, vec.size() - 1);
	cout << "\n\n\n";
	//printing top 20 and bottom 20 sorted data
	mat.printDataPartial(20, 20);
    return 0;
}

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
