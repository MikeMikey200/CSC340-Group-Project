#include "dataHandling.h"

int main()
{
    using namespace std;

    //sample of how to use Data class
    Data mat("student-mat.csv");
    
    mat.printDataPartial(10, 10);

    return 0;
}