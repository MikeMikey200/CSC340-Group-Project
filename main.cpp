#include "dataHandling.h"

int main()
{
    using namespace std;

    //sample of how to use Data class
    Data mat("student-mat.csv");

    cout << "hello world!" << endl;
    
    mat.printData();

    return 0;
}