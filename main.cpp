#include "Algorithm.h"

int main()
{
    using namespace std;

    //sample of how to use Data class
    Data mat("student-mat.csv");
    Data por("student-por.csv");

    Algorithm algorithm(mat, por);

    algorithm.printObeservationsAhmar();
    cout << "\n";
    algorithm.compareStudyAndDrinking();
    algorithm.ExpensesAndAlcoholConsumption();

    return 0;
}
