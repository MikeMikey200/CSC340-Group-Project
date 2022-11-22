#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "dataHandling.h" //Include Data class
class Algorithm{
public:
	//Constructor to initialize DataFunction class private member variables
	Algorithm(Data &file, Data &file2) {
		mat = file;
		por = file2;
	};

	//Using Minh's frequency function
	//Used for tallying the amount of students alcohol consumption (1-5) (verylow - veryhigh)
	//Takes the DAlc or WAlc vector as the parameter
	//Returns a vector containing the amount of students corresponding to each alcohol consumption level
	//index 0 corresponds to the total amount of students with very low alcohol consumption had in the course
	//index 1 corresponds to the total amount of students with low alcohol consumption had in the course
	std::vector<int> frequencyAhmar(std::vector<int> vec);

	//Ahmar's Function
	//A function to add up the total absences in each alcohol consumption level (1-5) (verylow - very high)
	//Takes in the DAlc or WAlc vector and the absences vector as parameters
	//Returns a vector containing the amount of absences corrseponding to each alcohol consumption level
	//index 0 corresponds to the total amount of absences that students with very low alcohol consumption had in the course
	//index 1 corresponds to the total amount of absences that students with low alcohol consumption had in the course
	std::vector<int> frequencyAbsentAhmar(std::vector<int> vec, std::vector<int> vec2);

	//Ahmar's Function
	//Function to print the averages of alcohol consumption (1-5)(verylow - veryhigh) and absences
	//Takes 4 parameters:
	//1. The vector returned from frequency() function
	//2. The vector returned from frequencyAbsent() function
	//3. An int value (0 or 1) where 0 corresonds to weekday and 1 corresponds to weekend
	//4. An int value (0 or 1) where 0 corresonds to the math course and 1 corresponds to the portuguese course
	void printAveragesAhmar(std::vector<int> frequency, std::vector<int> frequencyAbsent, int day, int course);

	void printObeservationsAhmar();


private:
	Data mat; //Data object for math course dataset
	Data por; //Data object for portuguese course dataset
};
#endif // !ALGORITHM
