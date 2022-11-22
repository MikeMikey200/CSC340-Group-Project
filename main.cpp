#include "dataHandling.h"
#include "Algorithm.h"

int main()
{
	Data mat("student-mat.csv"); //making a Data object and passing the mat.csv file as a parameter
	Data por("student-por.csv"); //making a Data object and passing the por.csv file as a parameter
	Algorithm func(mat, por); //making a DataFunction object and passing the Data objects as the parameters so the program can use the DataFunction class member functions on the Data objectS
	
	std::cout << "-------Math Course Weekday Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#16 with 4 parameters: 
	//1. Math Students Daily Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Math Students Daily Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekday
	//4. integer 0 which corresponds to math course
	func.printAveragesAhmar(func.frequencyAhmar(mat.getDAlc()),func.frequencyAbsentAhmar(mat.getDAlc(),mat.getAbsences()), 0, 0); 
	std::cout << std::endl;
	std::cout << "-------Math Course Weekend Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#24 with 4 parameters: 
	//1. Math Students Weekend Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Math Students Weekend Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekdend
	//4. integer 0 which corresponds to math course
	func.printAveragesAhmar(func.frequencyAhmar(mat.getWAlc()), func.frequencyAbsentAhmar(mat.getWAlc(), mat.getAbsences()), 1, 0);
	std::cout << std::endl;
	std::cout << "-------Portuguese Course Weekday Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#32 with 4 parameters: 
	//1. Portuguese Students Daily Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Portuguese Students Daily Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekday
	//4. integer 0 which corresponds to portuguese course
	func.printAveragesAhmar(func.frequencyAhmar(por.getDAlc()), func.frequencyAbsentAhmar(por.getDAlc(), por.getAbsences()), 0, 1);
	std::cout << std::endl;
	std::cout << "-------Portuguese Course Weekend Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#40 with 4 parameters: 
	//1. Portuguese Students Weekend Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Portuguese Students Weekend Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekdend
	//4. integer 0 which corresponds to portuguese course
	func.printAveragesAhmar(func.frequencyAhmar(por.getWAlc()), func.frequencyAbsentAhmar(por.getWAlc(), por.getAbsences()), 1, 1);
	
	//Print Observations
	func.printObeservationsAhmar();

	return 0;
}
