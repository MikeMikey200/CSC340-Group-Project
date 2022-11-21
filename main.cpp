#include "Algorithm.h"

template<typename T> void printVect(std::vector<T> vec, int num);
//Andre's funcitons
double findAverage(std::vector<int> vec, unsigned long begin, unsigned long end);
void compareStudyAndDrinking(Data mat, Data por);

int main()
{
    using namespace std;

    //sample of how to use Data class
    Data mat("student-mat.csv");
    Data por("student-por.csv");

    //sample how to use sort and print functions
    //printing top 20 and bottom 20 data
    mat.printDataPartial(5, 5);
    //targetting specifically absences vector
    vector<int> absences = mat.getAbsences();
    mat.sort(absences, 0, absences.size() - 1);
    cout << "\n\n\n";
    //printing top 20 and bottom 20 sorted data
    mat.printDataPartial(5, 5);

    Algorithm algorithm(mat, por);

    cout << "\n\n\n";
    algorithm.algorithm3();

    compareStudyAndDrinking(mat, por);

    return 0;
}



//Andre's funcitons
/**This function will find the average in a vector
 parameters: vector to find average of, and the beginning and end of where we want to find the average**/
double findAverage(std::vector<int> vec, unsigned long begin, unsigned long end) {
    int sum = 0;
    for (unsigned long i = begin; i < end; i++) {
        sum += vec.at(i);
    }
    double average = (double)sum / vec.size();
    return average;
}

/**This funciton will compare the study habits of students overall as compared to studnets who drink above average**/
void compareStudyAndDrinking(Data mat, Data por) {
    using namespace std;

    //find average study time for each data set
    double averageMatST = findAverage(mat.getStudytime(), 0, mat.getStudytime().size());
    double averagePorST = findAverage(por.getStudytime(), 0, por.getStudytime().size());

    //combine into one overall average
    double overallAverageST = (averageMatST + averagePorST) / 2.0;

    //find average weekly drinking habits for each student
    double averageMatWAlc = findAverage(mat.getWAlc(), 0, mat.getWAlc().size());
    double averagePorWAlc = findAverage(por.getWAlc(), 0, por.getWAlc().size());

    //find average weekend drinking habits for each student
    double averageMatDAlc = findAverage(mat.getDAlc(), 0, mat.getDAlc().size());
    double averagePorDAlc = findAverage(por.getDAlc(), 0, por.getDAlc().size());

    //combine into one overall drinking average
    double overallAverageAlc = (averageMatWAlc + averagePorWAlc + averageMatDAlc + averagePorDAlc) / 4.0;

    //cout << fixed << setprecision(2);
    cout << "The average study time overall for all students is " << overallAverageST << endl;
    cout << "The average drinking of all students is " << overallAverageAlc << endl;

    int sum = 0; //for average study time of people who drink more than average
    int counter = 0; //keep track of how many for average equation
    double tempDrinkAveMat = 0; //to average each student's drinking habits of week and weekend
    double tempDrinkAvePor = 0;
    //for loop to find average study time for people who drink above average compared to their peers
    for (unsigned long i = 0; i < mat.getWAlc().size(); i++) {

        tempDrinkAveMat = mat.getWAlc().at(i) + mat.getDAlc().at(i) / 2.0;
        tempDrinkAvePor = por.getWAlc().at(i) + por.getDAlc().at(i) / 2.0;

        if (tempDrinkAveMat > overallAverageAlc) {
            sum += mat.getStudytime().at(i);
            counter++;
        }
        if (tempDrinkAvePor > overallAverageAlc) {
            sum += por.getStudytime().at(i);
            counter++;
        }
    }

    double aveOfDrinkersStudyTime = (double)sum / counter;
    cout << "The average study time of students who drink above average is "
        << aveOfDrinkersStudyTime << endl;

    sum = 0; //reset values
    counter = 0;
    //for loop to check for students who drink under the average
    for (unsigned long i = 0; i < mat.getWAlc().size(); i++) {

        tempDrinkAveMat = mat.getWAlc().at(i) + mat.getDAlc().at(i) / 2.0;
        tempDrinkAvePor = por.getWAlc().at(i) + por.getDAlc().at(i) / 2.0;

        if (tempDrinkAveMat < overallAverageAlc) {
            sum += mat.getStudytime().at(i);
            counter++;
        }
        if (tempDrinkAvePor < overallAverageAlc) {
            sum += por.getStudytime().at(i);
            counter++;
        }
    }
    double aveOfNonDrinkersStudyTime = (double)sum / counter;
    cout << "The average study time of students who drink below average is "
        << aveOfNonDrinkersStudyTime << endl;
}
