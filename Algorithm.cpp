#include "Algorithm.h"

Algorithm::Algorithm() {}

Algorithm::Algorithm(Data mat, Data por) {
	this->mat = mat;
	this->por = por;
}

void Algorithm::printObeservationsAhmar()
{
	std::cout << "-------Math Course Weekday Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#16 with 4 parameters: 
	//1. Math Students Daily Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Math Students Daily Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekday
	//4. integer 0 which corresponds to math course
	printAverages(frequency(mat.getDAlc(), 5, 1), frequencyAbsent(mat.getDAlc(), mat.getAbsences()), 0, 0);
	std::cout << std::endl;
	std::cout << "-------Math Course Weekend Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#24 with 4 parameters: 
	//1. Math Students Weekend Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Math Students Weekend Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekdend
	//4. integer 0 which corresponds to math course
	printAverages(frequency(mat.getWAlc(), 5 ,1), frequencyAbsent(mat.getWAlc(), mat.getAbsences()), 1, 0);
	std::cout << std::endl;
	std::cout << "-------Portuguese Course Weekday Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#32 with 4 parameters: 
	//1. Portuguese Students Daily Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Portuguese Students Daily Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekday
	//4. integer 0 which corresponds to portuguese course
	printAverages(frequency(por.getDAlc(), 5, 1), frequencyAbsent(por.getDAlc(), por.getAbsences()), 0, 1);
	std::cout << std::endl;
	std::cout << "-------Portuguese Course Weekend Alcohol Consumption-------" << std::endl;
	//call printAverages() on line#40 with 4 parameters: 
	//1. Portuguese Students Weekend Alcohol Consumption vector
	//2. frequencyAbsent() function with parameters: Portuguese Students Weekend Alcohol Consumption vector, Absences vector
	//3. integer 0 which corresponds to weekdend
	//4. integer 0 which corresponds to portuguese course
	printAverages(frequency(por.getWAlc(), 5, 1), frequencyAbsent(por.getWAlc(), por.getAbsences()), 1, 1);
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

/**This funciton will compare the study habits of students overall as compared to studnets who drink above average**/
void Algorithm::compareStudyAndDrinking() {
    //find average study time for each data set
    double averageMatST = avg(mat.getStudytime(), 0, mat.getStudytime().size());
    double averagePorST = avg(por.getStudytime(), 0, por.getStudytime().size());

    //combine into one overall average
    double overallAverageST = (averageMatST + averagePorST) / 2.0;

    //find average weekly drinking habits for each student
    double averageMatWAlc = avg(mat.getWAlc(), 0, mat.getWAlc().size());
    double averagePorWAlc = avg(por.getWAlc(), 0, por.getWAlc().size());

    //find average weekend drinking habits for each student
    double averageMatDAlc = avg(mat.getDAlc(), 0, mat.getDAlc().size());
    double averagePorDAlc = avg(por.getDAlc(), 0, por.getDAlc().size());

    //get average drikning for mat Students
    double averageMatDrink = (averageMatWAlc + averageMatDAlc) / 2.0;
    
    //get average drinking for por students
    double averagePorDrink = (averagePorWAlc + averagePorDAlc) / 2.0;

    //combine into one overall drinking average
    double overallAverageAlc = (averageMatWAlc + averagePorWAlc + averageMatDAlc + averagePorDAlc) / 4.0;

    //for loop to find average study time for mat students who drink above or below average
    
    int sum = 0; //for average study time of people who drink more than average
    int sum2 = 0; //for average study time of people who drink below average
    int counter = 0; //keep track of how many for average equation of above average drinkers
    int counter2 = 0; //keep track of how many for average equation of below average drinkers
    double matStudentsAboveDrinkingStudyTimeAve = 0;
    int matAboveCounter = 0;
    double matStudentsBelowDrinkingStudyTimeAve = 0;
    int matBelowCounter = 0;
    double porStudentsAboveDrinkingStudyTimeAve = 0;
    int porAboveCounter = 0;
    double porStudendsBelowDrinkingStudyTimeAve = 0;
    int porBelowcounter = 0;
    double tempDrinkAveMat = 0; //to average each student's drinking habits of week and weekend
    double tempDrinkAvePor = 0;
    //for loop to find average study time for people who drink above or below average compared to their peers
    for (unsigned long i = 0; i < mat.getWAlc().size(); i++) {
        
        tempDrinkAveMat = mat.getWAlc().at(i) + mat.getDAlc().at(i) / 2.0;
        tempDrinkAvePor = por.getWAlc().at(i) + por.getDAlc().at(i) / 2.0;

        //get data for mat students
        if (tempDrinkAveMat > averageMatDrink){
            matStudentsAboveDrinkingStudyTimeAve += mat.getStudytime().at(i);
            matAboveCounter++;
        } else{
            matStudentsBelowDrinkingStudyTimeAve += mat.getStudytime().at(i);
            matBelowCounter++;
        }
        
        //get data for por students
        if (tempDrinkAvePor > averagePorDrink){
            porStudentsAboveDrinkingStudyTimeAve += mat.getStudytime().at(i);
            porAboveCounter++;
        } else{
            porStudendsBelowDrinkingStudyTimeAve += mat.getStudytime().at(i);
            porBelowcounter++;
        }
        

        if (tempDrinkAveMat > overallAverageAlc) {
            sum += mat.getStudytime().at(i);
            counter++;
        }else{
            sum2 += mat.getStudytime().at(i);
            counter2++;
        }
        
        if (tempDrinkAvePor > overallAverageAlc) {
            sum += por.getStudytime().at(i);
            counter++;
        }else{
            sum2 += por.getStudytime().at(i);
            counter2++;
        }
    }

    double aveOfDrinkersStudyTime = (double)sum / counter;
    double aveOfNonDrinkersStudyTime = (double)sum2 / counter2;
    matStudentsBelowDrinkingStudyTimeAve /= (double) matBelowCounter;
    matStudentsAboveDrinkingStudyTimeAve /= (double) matAboveCounter;
    porStudendsBelowDrinkingStudyTimeAve /= (double) porBelowcounter;
    porStudentsAboveDrinkingStudyTimeAve /= (double) porAboveCounter;


    std::cout << std::fixed << std::setprecision(2);
    std::cout << "-----MAT STUDENTS-----" << std::endl;
    std::cout << "The average study time was " << averageMatST << " hrs." << std::endl;
    std::cout << "The average weekly drinking rate was " << averageMatDAlc << "." << std::endl;
    std::cout << "The average weekend drinking rate was " << averageMatWAlc << "." << std::endl;
    std::cout << "The overall average drinking rate was "
    << (averageMatDAlc + averageMatWAlc) / 2.0  << "." << std::endl;
    std::cout << "The study time of students who drank above the overall average was "
    << matStudentsAboveDrinkingStudyTimeAve << " hrs." << std::endl;
    std::cout << "The study time of students who drank below the overall average was "
    << matStudentsBelowDrinkingStudyTimeAve << " hrs.\n" << std::endl;
    
    std::cout << "-----POR STUDENTS-----" << std::endl;
    std::cout << "The average study time was " << averagePorST << " hrs." << std::endl;
    std::cout << "The average weekly drinking rate was " << averagePorDAlc << "." << std::endl;
    std::cout << "The average weekend drinking rate was " << averagePorWAlc << "." << std::endl;
    std::cout << "The overall average drinking rate was "
    << (averagePorDAlc + averagePorWAlc) / 2.0  << "." << std::endl;
    std::cout << "The study time of students who drank above the overall average was "
    << porStudentsAboveDrinkingStudyTimeAve << "hrs." << std::endl;
    std::cout << "The study time of students who drank below the overall average was "
    << porStudendsBelowDrinkingStudyTimeAve << "hrs.\n" << std::endl;
    
    std::cout << "-----ALL STUDENTS-----" << std::endl;
    std::cout << "The average study time overall is " << overallAverageST << std::endl;
    std::cout << "The average weekly drinking rate was "
    << (averagePorDAlc + averageMatDAlc) / 2.0 << "." << std::endl;
    std::cout << "The average weekend drinking rate was "
    << (averagePorWAlc + averageMatWAlc) / 2.0 << "." << std::endl;
    std::cout << "The average drinking of all students is " << overallAverageAlc << std::endl;
    std::cout << "The average study time of students who drink above average is "
        << aveOfDrinkersStudyTime << " hrs." << std::endl;
    std::cout << "The average study time of students who drink below average is "
        << aveOfNonDrinkersStudyTime << " hrs.\n" << std::endl;
}

/*
* Comparing extra expenses to alcohol consumption for math and portuguese
* Using these dataset
* 16. schoolsup - extra educational support (binary: yes or no)
* 17. famsup - family educational support (binary: yes or no)
* 18. paid - extra paid classes within the course subject (Math or Portuguese) (binary: yes or no)
* 19. activities - extra-curricular activities (binary: yes or no)
* 20. nursery - attended nursery school (binary: yes or no)
* 21. higher - wants to take higher education (binary: yes or no)
* 22. internet - Internet access at home (binary: yes or no)
* 23. romantic - with a romantic relationship (binary: yes or no)
* 
* to
* 
* 27. Dalc - workday alcohol consumption (numeric: from 1 - very low to 5 - very high)
* 28. Walc - weekend alcohol consumption (numeric: from 1 - very low to 5 - very high)
*/
void Algorithm::ExpensesAndAlcoholConsumption() {
	//mat
	double avgMatSchoolSup = avg(mat.getSchoolsup(), 0, mat.getSchoolsup().size());
	double avgMatFamSup = avg(mat.getFamsup(), 0, mat.getFamsup().size());
	double avgMatPaid = avg(mat.getPaid(), 0, mat.getPaid().size());
	double avgMatActivities = avg(mat.getActivities(), 0, mat.getActivities().size());
	double avgMatNursery = avg(mat.getNursery(), 0, mat.getNursery().size());
	double avgMatHigher = avg(mat.getHigher(), 0, mat.getHigher().size());
	double avgMatInternet = avg(mat.getInternet(), 0, mat.getInternet().size());
	double avgMatRomantic = avg(mat.getRomantic(), 0, mat.getRomantic().size());
	std::vector<int> matDAlcFreq = frequency(mat.getDAlc(), 5, 1);
	std::vector<int> matWAlcFreq = frequency(mat.getWAlc(), 5, 1);
	double avgMatExpenses = (avgMatSchoolSup + avgMatFamSup + avgMatPaid + avgMatActivities + avgMatNursery + avgMatHigher + avgMatInternet + avgMatRomantic) / 8.0;
	double avgMatAlc = (avg(mat.getDAlc(), 0, mat.getDAlc().size()) + avg(mat.getWAlc(), 0, mat.getWAlc().size())) / 2.0;

	//por
	double avgPorSchoolSup = avg(por.getSchoolsup(), 0, por.getSchoolsup().size());
	double avgPorFamSup = avg(por.getFamsup(), 0, por.getFamsup().size());
	double avgPorPaid = avg(por.getPaid(), 0, por.getPaid().size());
	double avgPorActivities = avg(por.getActivities(), 0, por.getActivities().size());
	double avgPorNursery = avg(por.getNursery(), 0, por.getNursery().size());
	double avgPorHigher = avg(por.getHigher(), 0, por.getHigher().size());
	double avgPorInternet = avg(por.getInternet(), 0, por.getInternet().size());
	double avgPorRomantic = avg(por.getRomantic(), 0, por.getRomantic().size());
	std::vector<int> porDAlcFreq = frequency(por.getDAlc(), 5, 1);
	std::vector<int> porWAlcFreq = frequency(por.getWAlc(), 5, 1);
	double avgPorExpenses = (avgPorSchoolSup + avgPorFamSup + avgPorPaid + avgPorActivities + avgPorNursery + avgPorHigher + avgPorInternet + avgPorRomantic) / 8.0;
	double avgPorAlc = (avg(por.getDAlc(), 0, por.getDAlc().size()) + avg(por.getWAlc(), 0, por.getWAlc().size())) / 2.0;

	std::vector<int> matSchoolSupDAlc{ 0,0,0,0,0 };
	std::vector<int> matFamSupDAlc{ 0,0,0,0,0 };
	std::vector<int> matPaidDAlc{ 0,0,0,0,0 };
	std::vector<int> matActivitiesDAlc{ 0,0,0,0,0 };
	std::vector<int> matNurseryDAlc{ 0,0,0,0,0 };
	std::vector<int> matHigherDAlc{ 0,0,0,0,0 };
	std::vector<int> matInternetDAlc{ 0,0,0,0,0 };
	std::vector<int> matRomanticDAlc{ 0,0,0,0,0 };

	std::vector<int> matSchoolSupWAlc{ 0,0,0,0,0 };
	std::vector<int> matFamSupWAlc{ 0,0,0,0,0 };
	std::vector<int> matPaidWAlc{ 0,0,0,0,0 };
	std::vector<int> matActivitiesWAlc{ 0,0,0,0,0 };
	std::vector<int> matNurseryWAlc{ 0,0,0,0,0 };
	std::vector<int> matHigherWAlc{ 0,0,0,0,0 };
	std::vector<int> matInternetWAlc{ 0,0,0,0,0 };
	std::vector<int> matRomanticWAlc{ 0,0,0,0,0 };

	std::vector<int> matSchoolSupVec = mat.getSchoolsup();
	std::vector<int> matFamSupVec = mat.getFamsup();
	std::vector<int> matPaidVec = mat.getPaid();
	std::vector<int> matActivitiesVec = mat.getActivities();
	std::vector<int> matNurseryVec = mat.getNursery();
	std::vector<int> matHigherVec = mat.getHigher();
	std::vector<int> matInternetVec = mat.getInternet();
	std::vector<int> matRomanticVec = mat.getRomantic();

	std::vector<int> matDAlcVec = mat.getDAlc();
	std::vector<int> matWAlcVec = mat.getWAlc();

	for (unsigned int i = 0; i < matDAlcVec.size(); i++) {
		switch (matDAlcVec[i]) {
		case 1:
			if (matSchoolSupVec[i])
				matSchoolSupDAlc[0] = matSchoolSupDAlc[0] + 1;
			if (matFamSupVec[i])
				matFamSupDAlc[0] = matFamSupDAlc[0] + 1;
			if (matPaidVec[i])
				matPaidDAlc[0] = matPaidDAlc[0] + 1;
			if (matActivitiesVec[i])
				matActivitiesDAlc[0] = matActivitiesDAlc[0] + 1;
			if (matNurseryVec[i])
				matNurseryDAlc[0] = matNurseryDAlc[0] + 1;
			if (matHigherVec[i])
				matHigherDAlc[0] = matHigherDAlc[0] + 1;
			if (matInternetVec[i])
				matInternetDAlc[0] = matInternetDAlc[0] + 1;
			if (matRomanticVec[i])
				matRomanticDAlc[0] = matRomanticDAlc[0] + 1;
			break;
		case 2:
			if (matSchoolSupVec[i])
				matSchoolSupDAlc[1] = matSchoolSupDAlc[1] + 1;
			if (matFamSupVec[i])
				matFamSupDAlc[1] = matFamSupDAlc[1] + 1;
			if (matPaidVec[i])
				matPaidDAlc[1] = matPaidDAlc[1] + 1;
			if (matActivitiesVec[i])
				matActivitiesDAlc[1] = matActivitiesDAlc[1] + 1;
			if (matNurseryVec[i])
				matNurseryDAlc[1] = matNurseryDAlc[1] + 1;
			if (matHigherVec[i])
				matHigherDAlc[1] = matHigherDAlc[1] + 1;
			if (matInternetVec[i])
				matInternetDAlc[1] = matInternetDAlc[1] + 1;
			if (matRomanticVec[i])
				matRomanticDAlc[1] = matRomanticDAlc[1] + 1;
			break;
		case 3:
			if (matSchoolSupVec[i])
				matSchoolSupDAlc[2] = matSchoolSupDAlc[2] + 1;
			if (matFamSupVec[i])
				matFamSupDAlc[2] = matFamSupDAlc[2] + 1;
			if (matPaidVec[i])
				matPaidDAlc[2] = matPaidDAlc[2] + 1;
			if (matActivitiesVec[i])
				matActivitiesDAlc[2] = matActivitiesDAlc[2] + 1;
			if (matNurseryVec[i])
				matNurseryDAlc[2] = matNurseryDAlc[2] + 1;
			if (matHigherVec[i])
				matHigherDAlc[2] = matHigherDAlc[2] + 1;
			if (matInternetVec[i])
				matInternetDAlc[2] = matInternetDAlc[2] + 1;
			if (matRomanticVec[i])
				matRomanticDAlc[2] = matRomanticDAlc[2] + 1;
			break;
		case 4:
			if (matSchoolSupVec[i])
				matSchoolSupDAlc[3] = matSchoolSupDAlc[3] + 1;
			if (matFamSupVec[i])
				matFamSupDAlc[3] = matFamSupDAlc[3] + 1;
			if (matPaidVec[i])
				matPaidDAlc[3] = matPaidDAlc[3] + 1;
			if (matActivitiesVec[i])
				matActivitiesDAlc[3] = matActivitiesDAlc[3] + 1;
			if (matNurseryVec[i])
				matNurseryDAlc[3] = matNurseryDAlc[3] + 1;
			if (matHigherVec[i])
				matHigherDAlc[3] = matHigherDAlc[3] + 1;
			if (matInternetVec[i])
				matInternetDAlc[3] = matInternetDAlc[3] + 1;
			if (matRomanticVec[i])
				matRomanticDAlc[3] = matRomanticDAlc[3] + 1;
			break;
		case 5:
			if (matSchoolSupVec[i])
				matSchoolSupDAlc[4] = matSchoolSupDAlc[4] + 1;
			if (matFamSupVec[i])
				matFamSupDAlc[4] = matFamSupDAlc[4] + 1;
			if (matPaidVec[i])
				matPaidDAlc[4] = matPaidDAlc[4] + 1;
			if (matActivitiesVec[i])
				matActivitiesDAlc[4] = matActivitiesDAlc[4] + 1;
			if (matNurseryVec[i])
				matNurseryDAlc[4] = matNurseryDAlc[4] + 1;
			if (matHigherVec[i])
				matHigherDAlc[4] = matHigherDAlc[4] + 1;
			if (matInternetVec[i])
				matInternetDAlc[4] = matInternetDAlc[4] + 1;
			if (matRomanticVec[i])
				matRomanticDAlc[4] = matRomanticDAlc[4] + 1;
			break;
		}

		switch (matWAlcVec[i]) {
		case 1:
			if (matSchoolSupVec[i])
				matSchoolSupWAlc[0] = matSchoolSupWAlc[0] + 1;
			if (matFamSupVec[i])
				matFamSupWAlc[0] = matFamSupWAlc[0] + 1;
			if (matPaidVec[i])
				matPaidWAlc[0] = matPaidWAlc[0] + 1;
			if (matActivitiesVec[i])
				matActivitiesWAlc[0] = matActivitiesWAlc[0] + 1;
			if (matNurseryVec[i])
				matNurseryWAlc[0] = matNurseryWAlc[0] + 1;
			if (matHigherVec[i])
				matHigherWAlc[0] = matHigherWAlc[0] + 1;
			if (matInternetVec[i])
				matInternetWAlc[0] = matInternetWAlc[0] + 1;
			if (matRomanticVec[i])
				matRomanticWAlc[0] = matRomanticWAlc[0] + 1;
			break;
		case 2:
			if (matSchoolSupVec[i])
				matSchoolSupWAlc[1] = matSchoolSupWAlc[1] + 1;
			if (matFamSupVec[i])
				matFamSupWAlc[1] = matFamSupWAlc[1] + 1;
			if (matPaidVec[i])
				matPaidWAlc[1] = matPaidWAlc[1] + 1;
			if (matActivitiesVec[i])
				matActivitiesWAlc[1] = matActivitiesWAlc[1] + 1;
			if (matNurseryVec[i])
				matNurseryWAlc[1] = matNurseryWAlc[1] + 1;
			if (matHigherVec[i])
				matHigherWAlc[1] = matHigherWAlc[1] + 1;
			if (matInternetVec[i])
				matInternetWAlc[1] = matInternetWAlc[1] + 1;
			if (matRomanticVec[i])
				matRomanticWAlc[1] = matRomanticWAlc[1] + 1;
			break;
		case 3:
			if (matSchoolSupVec[i])
				matSchoolSupWAlc[2] = matSchoolSupWAlc[2] + 1;
			if (matFamSupVec[i])
				matFamSupWAlc[2] = matFamSupWAlc[2] + 1;
			if (matPaidVec[i])
				matPaidWAlc[2] = matPaidWAlc[2] + 1;
			if (matActivitiesVec[i])
				matActivitiesWAlc[2] = matActivitiesWAlc[2] + 1;
			if (matNurseryVec[i])
				matNurseryWAlc[2] = matNurseryWAlc[2] + 1;
			if (matHigherVec[i])
				matHigherWAlc[2] = matHigherWAlc[2] + 1;
			if (matInternetVec[i])
				matInternetWAlc[2] = matInternetWAlc[2] + 1;
			if (matRomanticVec[i])
				matRomanticWAlc[2] = matRomanticWAlc[2] + 1;
			break;
		case 4:
			if (matSchoolSupVec[i])
				matSchoolSupWAlc[3] = matSchoolSupWAlc[3] + 1;
			if (matFamSupVec[i])
				matFamSupWAlc[3] = matFamSupWAlc[3] + 1;
			if (matPaidVec[i])
				matPaidWAlc[3] = matPaidWAlc[3] + 1;
			if (matActivitiesVec[i])
				matActivitiesWAlc[3] = matActivitiesWAlc[3] + 1;
			if (matNurseryVec[i])
				matNurseryWAlc[3] = matNurseryWAlc[3] + 1;
			if (matHigherVec[i])
				matHigherWAlc[3] = matHigherWAlc[3] + 1;
			if (matInternetVec[i])
				matInternetWAlc[3] = matInternetWAlc[3] + 1;
			if (matRomanticVec[i])
				matRomanticWAlc[3] = matRomanticWAlc[3] + 1;
			break;
		case 5:
			if (matSchoolSupVec[i])
				matSchoolSupWAlc[4] = matSchoolSupWAlc[4] + 1;
			if (matFamSupVec[i])
				matFamSupWAlc[4] = matFamSupWAlc[4] + 1;
			if (matPaidVec[i])
				matPaidWAlc[4] = matPaidWAlc[4] + 1;
			if (matActivitiesVec[i])
				matActivitiesWAlc[4] = matActivitiesWAlc[4] + 1;
			if (matNurseryVec[i])
				matNurseryWAlc[4] = matNurseryWAlc[4] + 1;
			if (matHigherVec[i])
				matHigherWAlc[4] = matHigherWAlc[4] + 1;
			if (matInternetVec[i])
				matInternetWAlc[4] = matInternetWAlc[4] + 1;
			if (matRomanticVec[i])
				matRomanticWAlc[4] = matRomanticWAlc[4] + 1;
			break;
		}
	}

	std::vector<int> porSchoolSupDAlc{ 0,0,0,0,0 };
	std::vector<int> porFamSupDAlc{ 0,0,0,0,0 };
	std::vector<int> porPaidDAlc{ 0,0,0,0,0 };
	std::vector<int> porActivitiesDAlc{ 0,0,0,0,0 };
	std::vector<int> porNurseryDAlc{ 0,0,0,0,0 };
	std::vector<int> porHigherDAlc{ 0,0,0,0,0 };
	std::vector<int> porInternetDAlc{ 0,0,0,0,0 };
	std::vector<int> porRomanticDAlc{ 0,0,0,0,0 };

	std::vector<int> porSchoolSupWAlc{ 0,0,0,0,0 };
	std::vector<int> porFamSupWAlc{ 0,0,0,0,0 };
	std::vector<int> porPaidWAlc{ 0,0,0,0,0 };
	std::vector<int> porActivitiesWAlc{ 0,0,0,0,0 };
	std::vector<int> porNurseryWAlc{ 0,0,0,0,0 };
	std::vector<int> porHigherWAlc{ 0,0,0,0,0 };
	std::vector<int> porInternetWAlc{ 0,0,0,0,0 };
	std::vector<int> porRomanticWAlc{ 0,0,0,0,0 };

	std::vector<int> porSchoolSupVec = por.getSchoolsup();
	std::vector<int> porFamSupVec = por.getFamsup();
	std::vector<int> porPaidVec = por.getPaid();
	std::vector<int> porActivitiesVec = por.getActivities();
	std::vector<int> porNurseryVec = por.getNursery();
	std::vector<int> porHigherVec = por.getHigher();
	std::vector<int> porInternetVec = por.getInternet();
	std::vector<int> porRomanticVec = por.getRomantic();

	std::vector<int> porDAlcVec = por.getDAlc();
	std::vector<int> porWAlcVec = por.getWAlc();

	for (unsigned int i = 0; i < porDAlcVec.size(); i++) {
		switch (porDAlcVec[i]) {
		case 1:
			if (porSchoolSupVec[i])
				porSchoolSupDAlc[0] = porSchoolSupDAlc[0] + 1;
			if (porFamSupVec[i])
				porFamSupDAlc[0] = porFamSupDAlc[0] + 1;
			if (porPaidVec[i])
				porPaidDAlc[0] = porPaidDAlc[0] + 1;
			if (porActivitiesVec[i])
				porActivitiesDAlc[0] = porActivitiesDAlc[0] + 1;
			if (porNurseryVec[i])
				porNurseryDAlc[0] = porNurseryDAlc[0] + 1;
			if (porHigherVec[i])
				porHigherDAlc[0] = porHigherDAlc[0] + 1;
			if (porInternetVec[i])
				porInternetDAlc[0] = porInternetDAlc[0] + 1;
			if (porRomanticVec[i])
				porRomanticDAlc[0] = porRomanticDAlc[0] + 1;
			break;
		case 2:
			if (porSchoolSupVec[i])
				porSchoolSupDAlc[1] = porSchoolSupDAlc[1] + 1;
			if (porFamSupVec[i])
				porFamSupDAlc[1] = porFamSupDAlc[1] + 1;
			if (porPaidVec[i])
				porPaidDAlc[1] = porPaidDAlc[1] + 1;
			if (porActivitiesVec[i])
				porActivitiesDAlc[1] = porActivitiesDAlc[1] + 1;
			if (porNurseryVec[i])
				porNurseryDAlc[1] = porNurseryDAlc[1] + 1;
			if (porHigherVec[i])
				porHigherDAlc[1] = porHigherDAlc[1] + 1;
			if (porInternetVec[i])
				porInternetDAlc[1] = porInternetDAlc[1] + 1;
			if (porRomanticVec[i])
				porRomanticDAlc[1] = porRomanticDAlc[1] + 1;
			break;
		case 3:
			if (porSchoolSupVec[i])
				porSchoolSupDAlc[2] = porSchoolSupDAlc[2] + 1;
			if (porFamSupVec[i])
				porFamSupDAlc[2] = porFamSupDAlc[2] + 1;
			if (porPaidVec[i])
				porPaidDAlc[2] = porPaidDAlc[2] + 1;
			if (porActivitiesVec[i])
				porActivitiesDAlc[2] = porActivitiesDAlc[2] + 1;
			if (porNurseryVec[i])
				porNurseryDAlc[2] = porNurseryDAlc[2] + 1;
			if (porHigherVec[i])
				porHigherDAlc[2] = porHigherDAlc[2] + 1;
			if (porInternetVec[i])
				porInternetDAlc[2] = porInternetDAlc[2] + 1;
			if (porRomanticVec[i])
				porRomanticDAlc[2] = porRomanticDAlc[2] + 1;
			break;
		case 4:
			if (porSchoolSupVec[i])
				porSchoolSupDAlc[3] = porSchoolSupDAlc[3] + 1;
			if (porFamSupVec[i])
				porFamSupDAlc[3] = porFamSupDAlc[3] + 1;
			if (porPaidVec[i])
				porPaidDAlc[3] = porPaidDAlc[3] + 1;
			if (porActivitiesVec[i])
				porActivitiesDAlc[3] = porActivitiesDAlc[3] + 1;
			if (porNurseryVec[i])
				porNurseryDAlc[3] = porNurseryDAlc[3] + 1;
			if (porHigherVec[i])
				porHigherDAlc[3] = porHigherDAlc[3] + 1;
			if (porInternetVec[i])
				porInternetDAlc[3] = porInternetDAlc[3] + 1;
			if (porRomanticVec[i])
				porRomanticDAlc[3] = porRomanticDAlc[3] + 1;
			break;
		case 5:
			if (porSchoolSupVec[i])
				porSchoolSupDAlc[4] = porSchoolSupDAlc[4] + 1;
			if (porFamSupVec[i])
				porFamSupDAlc[4] = porFamSupDAlc[4] + 1;
			if (porPaidVec[i])
				porPaidDAlc[4] = porPaidDAlc[4] + 1;
			if (porActivitiesVec[i])
				porActivitiesDAlc[4] = porActivitiesDAlc[4] + 1;
			if (porNurseryVec[i])
				porNurseryDAlc[4] = porNurseryDAlc[4] + 1;
			if (porHigherVec[i])
				porHigherDAlc[4] = porHigherDAlc[4] + 1;
			if (porInternetVec[i])
				porInternetDAlc[4] = porInternetDAlc[4] + 1;
			if (porRomanticVec[i])
				porRomanticDAlc[4] = porRomanticDAlc[4] + 1;
			break;
		}

		switch (porWAlcVec[i]) {
		case 1:
			if (porSchoolSupVec[i])
				porSchoolSupWAlc[0] = porSchoolSupWAlc[0] + 1;
			if (porFamSupVec[i])
				porFamSupWAlc[0] = porFamSupWAlc[0] + 1;
			if (porPaidVec[i])
				porPaidWAlc[0] = porPaidWAlc[0] + 1;
			if (porActivitiesVec[i])
				porActivitiesWAlc[0] = porActivitiesWAlc[0] + 1;
			if (porNurseryVec[i])
				porNurseryWAlc[0] = porNurseryWAlc[0] + 1;
			if (porHigherVec[i])
				porHigherWAlc[0] = porHigherWAlc[0] + 1;
			if (porInternetVec[i])
				porInternetWAlc[0] = porInternetWAlc[0] + 1;
			if (porRomanticVec[i])
				porRomanticWAlc[0] = porRomanticWAlc[0] + 1;
			break;
		case 2:
			if (porSchoolSupVec[i])
				porSchoolSupWAlc[1] = porSchoolSupWAlc[1] + 1;
			if (porFamSupVec[i])
				porFamSupWAlc[1] = porFamSupWAlc[1] + 1;
			if (porPaidVec[i])
				porPaidWAlc[1] = porPaidWAlc[1] + 1;
			if (porActivitiesVec[i])
				porActivitiesWAlc[1] = porActivitiesWAlc[1] + 1;
			if (porNurseryVec[i])
				porNurseryWAlc[1] = porNurseryWAlc[1] + 1;
			if (porHigherVec[i])
				porHigherWAlc[1] = porHigherWAlc[1] + 1;
			if (porInternetVec[i])
				porInternetWAlc[1] = porInternetWAlc[1] + 1;
			if (porRomanticVec[i])
				porRomanticWAlc[1] = porRomanticWAlc[1] + 1;
			break;
		case 3:
			if (porSchoolSupVec[i])
				porSchoolSupWAlc[2] = porSchoolSupWAlc[2] + 1;
			if (porFamSupVec[i])
				porFamSupWAlc[2] = porFamSupWAlc[2] + 1;
			if (porPaidVec[i])
				porPaidWAlc[2] = porPaidWAlc[2] + 1;
			if (porActivitiesVec[i])
				porActivitiesWAlc[2] = porActivitiesWAlc[2] + 1;
			if (porNurseryVec[i])
				porNurseryWAlc[2] = porNurseryWAlc[2] + 1;
			if (porHigherVec[i])
				porHigherWAlc[2] = porHigherWAlc[2] + 1;
			if (porInternetVec[i])
				porInternetWAlc[2] = porInternetWAlc[2] + 1;
			if (porRomanticVec[i])
				porRomanticWAlc[2] = porRomanticWAlc[2] + 1;
			break;
		case 4:
			if (porSchoolSupVec[i])
				porSchoolSupWAlc[3] = porSchoolSupWAlc[3] + 1;
			if (porFamSupVec[i])
				porFamSupWAlc[3] = porFamSupWAlc[3] + 1;
			if (porPaidVec[i])
				porPaidWAlc[3] = porPaidWAlc[3] + 1;
			if (porActivitiesVec[i])
				porActivitiesWAlc[3] = porActivitiesWAlc[3] + 1;
			if (porNurseryVec[i])
				porNurseryWAlc[3] = porNurseryWAlc[3] + 1;
			if (porHigherVec[i])
				porHigherWAlc[3] = porHigherWAlc[3] + 1;
			if (porInternetVec[i])
				porInternetWAlc[3] = porInternetWAlc[3] + 1;
			if (porRomanticVec[i])
				porRomanticWAlc[3] = porRomanticWAlc[3] + 1;
			break;
		case 5:
			if (porSchoolSupVec[i])
				porSchoolSupWAlc[4] = porSchoolSupWAlc[4] + 1;
			if (porFamSupVec[i])
				porFamSupWAlc[4] = porFamSupWAlc[4] + 1;
			if (porPaidVec[i])
				porPaidWAlc[4] = porPaidWAlc[4] + 1;
			if (porActivitiesVec[i])
				porActivitiesWAlc[4] = porActivitiesWAlc[4] + 1;
			if (porNurseryVec[i])
				porNurseryWAlc[4] = porNurseryWAlc[4] + 1;
			if (porHigherVec[i])
				porHigherWAlc[4] = porHigherWAlc[4] + 1;
			if (porInternetVec[i])
				porInternetWAlc[4] = porInternetWAlc[4] + 1;
			if (porRomanticVec[i])
				porRomanticWAlc[4] = porRomanticWAlc[4] + 1;
			break;
		}
	}

	std::vector<int> matSumDAlc = { 0,0,0,0,0 };
	std::vector<int> matSumWAlc = { 0,0,0,0,0 };

	for (unsigned int i = 0; i < matSumDAlc.size(); i++) {
		matSumDAlc[i] = matSumDAlc[i] + 
						matSchoolSupDAlc[i] + 
						matFamSupDAlc[i] + 
						matPaidDAlc[i] + 
						matActivitiesDAlc[i] + 
						matNurseryDAlc[i] + 
						matHigherDAlc[i] + 
						matInternetDAlc[i] + 
						matRomanticDAlc[i];

		matSumWAlc[i] = matSumWAlc[i] +
			matSchoolSupWAlc[i] +
			matFamSupWAlc[i] +
			matPaidWAlc[i] +
			matActivitiesWAlc[i] +
			matNurseryWAlc[i] +
			matHigherWAlc[i] +
			matInternetWAlc[i] +
			matRomanticWAlc[i];
	}

	std::vector<double> matSumAvg = { 0,0,0,0,0 };
	std::vector<double> matFreqAvg = { 0,0,0,0,0 };
	double matSum = 0;

	for (unsigned int i = 0; i < matSumDAlc.size(); i++) {
		matSumAvg[i] = ((((double)matSumDAlc[i] + (double) matSumWAlc[i]) / 2.0) / ((double) matSchoolSupVec.size() * 5.0)) * 100.0;
		matFreqAvg[i] = ((((double)matDAlcFreq[i] + (double)matWAlcFreq[i]) / 2.0) / ((double) matSchoolSupVec.size())) * 100.0;
		matSum += matSumAvg[i];
	}

	std::vector<int> porSumDAlc = { 0,0,0,0,0 };
	std::vector<int> porSumWAlc = { 0,0,0,0,0 };

	for (unsigned int i = 0; i < porSumDAlc.size(); i++) {
		porSumDAlc[i] = porSumDAlc[i] +
			porSchoolSupDAlc[i] +
			porFamSupDAlc[i] +
			porPaidDAlc[i] +
			porActivitiesDAlc[i] +
			porNurseryDAlc[i] +
			porHigherDAlc[i] +
			porInternetDAlc[i] +
			porRomanticDAlc[i];

		porSumWAlc[i] = porSumWAlc[i] +
			porSchoolSupWAlc[i] +
			porFamSupWAlc[i] +
			porPaidWAlc[i] +
			porActivitiesWAlc[i] +
			porNurseryWAlc[i] +
			porHigherWAlc[i] +
			porInternetWAlc[i] +
			porRomanticWAlc[i];
	}

	std::vector<double> porSumAvg = { 0,0,0,0,0 };
	std::vector<double> porFreqAvg = { 0,0,0,0,0 };
	double porSum = 0;

	for (unsigned int i = 0; i < porSumDAlc.size(); i++) {
		porSumAvg[i] = ((((double)porSumDAlc[i] + (double)porSumWAlc[i]) / 2.0) / ((double)porSchoolSupVec.size() * 5)) * 100.0;
		porFreqAvg[i] = ((((double)porDAlcFreq[i] + (double)porWAlcFreq[i]) / 2.0) / ((double)porSchoolSupVec.size())) * 100.0;
		porSum += porSumAvg[i];
	}

	std::cout << "---------------------------Math course---------------------------";
	std::cout << "\nThe weekdays consumption of alcohol for the math course:\n";
	printFrequency(matDAlcFreq, 0);
	std::cout << "\nThe average of alcohol consumption for weekdays: " << avg(matDAlcVec, 0, matDAlcVec.size()) << "\n";
	std::cout << "\nThe weekends consumption of alcohol for the math course:\n";
	printFrequency(matWAlcFreq, 0);
	std::cout << "\nThe average of alcohol consumption for weekends: " << avg(matWAlcVec, 0, matWAlcVec.size()) << "\n";
	std::cout << "\nAn increased of " << (avg(matWAlcVec, 0, matWAlcVec.size()) + avg(matDAlcVec, 0, matDAlcVec.size())) / avg(matWAlcVec, 0, matWAlcVec.size()) * 100.0 << "% in alcohol consumption going from weekdays into weekends\n";
	
	std::cout << "\nApproximate " << std::setprecision(3) << matSum << "% of the students in math course has gotten some form of outside of school support. (n = " << matSchoolSupVec.size() << ")\n";
	std::cout << 1 << ": " << matSumAvg[0] << "% of the students has very low alcohol consumption.\n";
	std::cout << " : " << matSumAvg[0] / matFreqAvg[0] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 2 << ": " << matSumAvg[1] << "% of the students has low alcohol consumption.\n";
	std::cout << " : " << matSumAvg[1] / matFreqAvg[1] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 3 << ": " << matSumAvg[2] << "% of the students has medium alcohol consumption.\n";
	std::cout << " : " << matSumAvg[2] / matFreqAvg[2] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 4 << ": " << matSumAvg[3] << "% of the students has high alcohol consumption.\n";
	std::cout << " : " << matSumAvg[3] / matFreqAvg[3] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 5 << ": " << matSumAvg[4] << "% of the students has very high alcohol consumption.\n";
	std::cout << " : " << matSumAvg[4] / matFreqAvg[4] * 100.0 << "% chances student likely to have an outside of school support.\n\n";

	std::cout << " : " << avgMatSchoolSup * 100.0 << "% of the students has extra educational support.\n";
	std::cout << " : " << avgMatFamSup * 100.0 << "% of the students has family educational support.\n";
	std::cout << " : " << avgMatPaid * 100.0 << "% of the students has extra paid classes within the course subject.\n";
	std::cout << " : " << avgMatActivities * 100.0 << "% of the students has extra-curricular activities.\n";
	std::cout << " : " << avgMatNursery * 100.0 << "% of the students has attended nursery school.\n";
	std::cout << " : " << avgMatHigher * 100.0 << "% of the students wants to take higher education.\n";
	std::cout << " : " << avgMatInternet * 100.0 << "% of the students has internet access at home.\n";
	std::cout << " : " << avgMatRomantic * 100.0 << "% of the students has a romantic relationship.\n\n";

	std::cout << " : " << avgMatExpenses * 100.0 << "% of overall outside of school supports the students has.\n\n";

	std::cout << "---------------------------Portuguese course---------------------------";
	std::cout << "\nThe weekdays consumption of alcohol for the portuguese course:\n";
	printFrequency(porDAlcFreq, 1);
	std::cout << "\nThe average of alcohol consumption for weekdays: " << avg(porDAlcVec, 0, porDAlcVec.size()) << "\n";
	std::cout << "\nThe weekends consumption of alcohol for the portuguese course:\n";
	printFrequency(porWAlcFreq, 1);
	std::cout << "\nThe average of alcohol consumption for weekdays: " << avg(porWAlcVec, 0, porWAlcVec.size()) << "\n";
	std::cout << "\nAn increased of " << (avg(porWAlcVec, 0, porWAlcVec.size()) + avg(porDAlcVec, 0, porDAlcVec.size())) / avg(porWAlcVec, 0, porWAlcVec.size()) * 100.0 << "% in alcohol consumption going from weekdays into weekends\n";

	std::cout << "\nApproximate " << std::setprecision(3) << porSum << "% of the students in portueguese course has gotten some form of outside of school support. (n = " << porSchoolSupVec.size() << ")\n";
	std::cout << 1 << ": " << porSumAvg[0] << "% of the students has very low alcohol consumption.\n";
	std::cout << " : " << porSumAvg[0] / porFreqAvg[0] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 2 << ": " << porSumAvg[1] << "% of the students has low alcohol consumption.\n";
	std::cout << " : " << porSumAvg[1] / porFreqAvg[1] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 3 << ": " << porSumAvg[2] << "% of the students has medium alcohol consumption.\n";
	std::cout << " : " << porSumAvg[2] / porFreqAvg[2] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 4 << ": " << porSumAvg[3] << "% of the students has high alcohol consumption.\n";
	std::cout << " : " << porSumAvg[3] / porFreqAvg[3] * 100.0 << "% chances student likely to have an outside of school support.\n\n";
	std::cout << 5 << ": " << porSumAvg[4] << "% of the students has very high alcohol consumption.\n";
	std::cout << " : " << porSumAvg[4] / porFreqAvg[4] * 100.0 << "% chances student likely to have an outside of school support.\n\n";

	std::cout << " : " << avgPorSchoolSup * 100.0 << "% of the students has extra educational support.\n";
	std::cout << " : " << avgPorFamSup * 100.0 << "% of the students has family educational support.\n";
	std::cout << " : " << avgPorPaid * 100.0 << "% of the students has extra paid classes within the course subject.\n";
	std::cout << " : " << avgPorActivities * 100.0 << "% of the students has extra-curricular activities.\n";
	std::cout << " : " << avgPorNursery * 100.0 << "% of the students has attended nursery school.\n";
	std::cout << " : " << avgPorHigher * 100.0 << "% of the students wants to take higher education.\n";
	std::cout << " : " << avgPorInternet * 100.0 << "% of the students has internet access at home.\n";
	std::cout << " : " << avgPorRomantic * 100.0 << "% of the students has a romantic relationship.\n\n";

	std::cout << " : " << avgPorExpenses * 100.0 << "% of overall outside of school supports the students has.\n\n";

	std::cout << " : " << "The average alcohol consumption of portuguese course is " << std::setprecision(5) << (avgPorAlc - avgMatAlc) / avgMatAlc * 100.0 << "% higher than math course. (a very small and negligible number when comparing the two courses)\n\n";

	std::cout << "Observation 1: The students are more like to have a higher alcohol consumptions when having less outside of school support, as this is a trend for both math course and portuguese course.\n";
	std::cout << "Observation 2: Likely than not, alcohol consumptions shouldn't be much of a different when attending a math or a portuguese course.\n";
	std::cout << "Observation 3: Students are more likely to drink way more often during weekends than weekdays\n\n";
}

/**This function will find the average in a vector
 parameters: vector to find average of, and the beginning and end of where we want to find the average**/
double Algorithm::avg(std::vector<int> vec, int beg, int end) {
	int sum = 0;
	for (; beg < end; beg++) {
		sum += vec[beg];
	}
	return sum / (double) vec.size();
}

//return a vector of frequencies for data
std::vector<int> Algorithm::frequency(std::vector<int> vec, unsigned int set, int indicesFixing) {
	std::vector<int> vecMode{};
	for (unsigned int i = 0; i < set; i++) {
		vecMode.push_back(0);
	}
	for (unsigned int i = 0; i < vec.size(); i++) {
		vecMode[vec[i] - indicesFixing] = vecMode[vec[i] - indicesFixing] + 1;
	}
	return vecMode;
}

//printing the vector of frequency in %
void Algorithm::printFrequency(std::vector<int> frequency, int course) {
	if (!course) {
		for (unsigned int i = 0; i < frequency.size(); i++) {
			switch (i + 1) {
			case 1:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double)mat.getAbsences().size() * 100 << "%" << " of the students has very low alcohol consumption." << std::endl;
				break;
			case 2:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double) mat.getAbsences().size() * 100 << "%" << " of the students has low alcohol consumption." << std::endl;
				break;
			case 3:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double) mat.getAbsences().size() * 100 << "%" << " of the students has medium alcohol consumption." << std::endl;
				break;
			case 4:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double) mat.getAbsences().size() * 100 << "%" << " of the students has high alcohol consumption." << std::endl;
				break;
			case 5:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double) mat.getAbsences().size() * 100 << "%" << " of the students has very high alcohol consumption." << std::endl;
				break;
			}
		}
	}
	else {
		for (unsigned int i = 0; i < frequency.size(); i++) {
			switch (i + 1) {
			case 1:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of the students has very low alcohol consumption." << std::endl;
				break;
			case 2:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of the students has low alcohol consumption." << std::endl;
				break;
			case 3:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of the students has medium alcohol consumption." << std::endl;
				break;
			case 4:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of the students has high alcohol consumption." << std::endl;
				break;
			case 5:
				std::cout << i + 1 << ": " << std::setprecision(3) << frequency[i] / (double)por.getAbsences().size() * 100 << "%" << " of the students has very high alcohol consumption." << std::endl;
				break;
			}
		}
	}
}

//Ahmar's Function
//A function to add up the total absences in each alcohol consumption level (1-5) (verylow - veryhigh)
//Takes in the DAlc or WAlc vector and the absences vector as parameters
//Returns a vector containing the amount of absences corrseponding to each alcohol consumption level
//index 0 corresponds to the total amount of absences that students with very low alcohol consumption had in the course
//index 1 corresponds to the total amount of absences that students with low alcohol consumption had in the course
std::vector<int> Algorithm::frequencyAbsent(std::vector<int> vec, std::vector<int> vec2) {
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
//3. An int value (0 or 1) where 0 corresonds to weekday and 1 corresponds to weekend
//4. An int value (0 or 1) where 0 corresonds to the math course and 1 corresponds to the portuguese course
void Algorithm::printAverages(std::vector<int> frequency, std::vector<int> frequencyAbsent, int day, int course) {
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
