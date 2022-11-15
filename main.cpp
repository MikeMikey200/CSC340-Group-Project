#include "dataHandling.h"

int main()
{
    using namespace std;

    //sample of how to use Data class
    Data mat("student-mat.csv");
    vector<int> matG1 = mat.getG1();
    for (int num : matG1) {
        cout << num << endl;
    }
    return 0;
}