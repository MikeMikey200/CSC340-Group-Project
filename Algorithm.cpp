#include "algorithm.h"

//Using Minh's frequency function
//Used for tallying the amount of students alcohol consumption (1-5) (verylow - veryhigh)
//Takes the DAlc or WAlc vector as the parameter
//Returns a vector containing the amount of students corresponding to each alcohol consumption level
//index 0 corresponds to the total amount of students with very low alcohol consumption had in the course
//index 1 corresponds to the total amount of students with low alcohol consumption had in the course
std::vector<int> Algorithm::frequencyAhmar(std::vector<int> vec) {
	std::vector<int> vecFreq{ 0, 0, 0, 0, 0 };
	for (unsigned int i = 0; i < vec.size(); i++) {
		vecFreq[vec[i] - 1] = vecFreq[vec[i] - 1] + 1;
	}
	return vecFreq;
}

//Ahmar's Function
//A function to add up the total absences in each alcohol consumption level (1-5) (verylow - veryhigh)
//Takes in the DAlc or WAlc vector and the absences vector as parameters
//Returns a vector containing the amount of absences corrseponding to each alcohol consumption level
//index 0 corresponds to the total amount of absences that students with very low alcohol consumption had in the course
//index 1 corresponds to the total amount of absences that students with low alcohol consumption had in the course
std::vector<int> Algorithm::frequencyAbsentAhmar(std::vector<int> vec, std::vector<int> vec2) {
	std::vector<int> vecAbsent{ 0, 0, 0, 0, 0 };
	for (unsigned int i = 0; i < vec.size(); i++) {
		switch (vec[i]) {
		case 1:
			vecAbsent[0] = vecAbsent[0] + vec2[i];
			break;
		case 2:
			vecAbsent[1] = vecAbsent[1] + vec2[i];
			break;
		case 3:
			vecAbsent[2] = vecAbsent[2] + vec2[i];
			break;
		case 4:
			vecAbsent[3] = vecAbsent[3] + vec2[i];
			break;
		case 5:
			vecAbsent[4] = vecAbsent[4] + vec2[i];
			break;
		}
	}
	return vecAbsent;
}

//Ahmar's Function
//Function to print the averages of alcohol consumption (1-5)(verylow - veryhigh) and absences
//Takes 4 parameters:
//1. The vector returned from frequency() function
//2. The vector returned from frequencyAbsent() function
//3. An int value (0 or 1) where 0 corresponds to weekday and 1 corresponds to weekend
//4. An int value (0 or 1) where 0 corresponds to the math course and 1 corresponds to the portuguese course
void Algorithm::printAveragesAhmar(std::vector<int> frequency, std::vector<int> frequencyAbsent, int day, int course) {
	int totalAbsences = 0; //int variable to hold the total amount of absences in the course
	for (unsigned int i = 0; i < frequencyAbsent.size(); i++) { //loop through the frequencyAbsent vector where each index contains an amount of absences and add them to totalAbsences
		totalAbsences = totalAbsences + frequencyAbsent[i];
	}

	if (!course) { //if math course
		if (!day) { //if weekday alcohol consumption
			for (unsigned int i = 0; i < frequency.size(); i++) { //loop through the frequceny and frequencyAbsent vectors and divide each index by their respective totals and multiply it by 100 for a % value
				switch (i + 1) {
				case 1: //case where i == 0
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had very low weekday alcohol consumption and had "  //amount of students with verylow weekday alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with verylow weekday alcohol consumption divided by total amount of absences in the course
					break;
				case 2: //case where i == 1
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had low weekday alcohol consumption and had " //amount of students with low weekday alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with low weekday alcohol consumption divided by total amount of absences in the course
					break;
				case 3: //case where i == 2
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had medium weekday alcohol consumption and had " //amount of students with medium weekday alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with medium weekday alcohol consumption divided by total amount of absences in the course
					break;
				case 4: //case where i == 3
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had high weekday alcohol consumption and had " //amount of students with high weekday alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with high weekday alcohol consumption divided by total amount of absences in the course
					break;
				case 5: //case where i == 4
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had very high weekday alcohol consumption and had " //amount of students with very high weekday alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with very high weekday alcohol consumption divided by total amount of absences in the course
					break;
				}
			}
		}
		else { //if weekend alcohol consumption
			for (unsigned int i = 0; i < frequency.size(); i++) { //loop through the frequceny and frequencyAbsent vectors and divide each index by their respective totals and multiply it by 100 for a % value
				switch (i + 1) {
				case 1:
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had very low weekend alcohol consumption and had " //amount of students with verylow weekend alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with verylow weekend alcohol consumption divided by total amount of absences in the course
					break;
				case 2:
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had low weekend alcohol consumption and had " //amount of students with low weekend alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with low weekend alcohol consumption divided by total amount of absences in the course
					break;
				case 3:
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had medium weekend alcohol consumption and had " //amount of students with medium weekend alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with medium weekend alcohol consumption divided by total amount of absences in the course
					break;
				case 4:
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had high weekend alcohol consumption and had " //amount of students with high weekend alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with high weekend alcohol consumption divided by total amount of absences in the course
					break;
				case 5:
					std::cout << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of students had very high weekend alcohol consumption and had " //amount of students with very high weekend alcohol consumption divided by total amount of students
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl; //amount of absences from students with very high weekend alcohol consumption divided by total amount of absences in the course
					break;
				}
			}
		}
	}
	else { //if portuguese course
		if (!day) { //if weekday alcohol consumption
			for (unsigned int i = 0; i < frequency.size(); i++) {
				switch (i + 1) {
				case 1:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had very low weekday alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 2:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had low weekday alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 3:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had medium weekday alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 4:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had high weekday alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 5:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had very high weekday alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				}
			}
		}
		else { //if weekend alcohol consumption
			for (unsigned int i = 0; i < frequency.size(); i++) {
				switch (i + 1) {
				case 1:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had very low weekend alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 2:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had low weekend alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 3:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had medium weekend alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 4:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had high weekend alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				case 5:
					std::cout << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of students had very high weekend alcohol consumption and had "
						<< std::setprecision(3) << frequencyAbsent[i] / (double)totalAbsences * 100 << "% of the total absences." << std::endl;
					break;
				}
			}
		}
	}
}

void Algorithm::printObeservationsAhmar()
{

	//Print Observations
	std::cout << std::endl;
	std::cout << "-------Observations--------" << std::endl;
	std::cout << "----Weekday Alcohol Consumption----" << std::endl;
	std::cout << "1. Weekday alcohol consumption has little correlation to absents for students in both courses." << std::endl;
	std::cout << "2. Students with very low to low weekday alcohol consumption still had approximately atleast 82% of the total absents" << std::endl;
	std::cout << "   while students with medium to very high weekday alcohol consumption only had approximately at most 18% of the total absents." << std::endl;
	std::cout << "3. 88.9% of math students had very low to low weekday alcohol consumption, but they also had 84.6% of the total absents while" << std::endl;
	std::cout << "   the other 11.14 % had medium to very high weekday alcohol consumption and only 15.39% of the total absents." << std::endl;
	std::cout << "4. 88.1% of portuguese students had very low to low weekday alcohol consumption, but they also had 82.4 % of the total absents while the" << std::endl;
	std::cout << "   other 11.87% had medium to very high weekday alcohol consumption and only 17.64% of total absents." << std::endl;
	std::cout << "----Weekend Alcohol Consumption----" << std::endl;
	std::cout << "1. Weekend alcohol consumption has a stronger correlation to absents for students in both courses." << std::endl;
	std::cout << "2. Students with very low to low weekend alcohol consumption still had approximately 50% of the" << std::endl;
	std::cout << "   total absents while students with medium to very high weekend alcohol consumption had approximately" << std::endl;
	std::cout << "   the other 50% of the total absents." << std::endl;
	std::cout << "3. 59.7% of math students had very low to low weekend alcohol consumption with 49.8% of total absents" << std::endl;
	std::cout << "   and students with medium to very high weekend alcohol consumption with 50.16% of the other total absents." << std::endl;
	std::cout << "4. 61.2% of portuguese students had very low to low weekend alcohol consumption with 53.4% of the total" << std::endl;
	std::cout << "   and students with medium to very high weekend alcohol consumption with 46.64% of the other total absents." << std::endl;
}
