//
// Created by Alexander P on 20/05/20.
//

#include "lambdaFunction.h"
#include "my_header"

using namespace std;

vector<int> GenerateRandVect(int numOfNums, int min, int max){
    vector<int> vecValues;
    srand(time(NULL));
    int i = 0, randVal = 0;

    while (i < numOfNums){
        randVal = min + rand()%((max+1)-min);
        vecValues.push_back(randVal);
        i++;
    }
    return vecValues;
}
