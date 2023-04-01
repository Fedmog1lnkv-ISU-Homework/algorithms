#include <iostream>
#include "NDArray.h"
#include "ExampleFunctions.hpp"

int main()
{

    defaultConstructor();
    zerosExample();
    onesExample();
    randomIntExample();
    randomFloatExample();
    additionOperator();
    subtractionOperator();
    multiplicationOperator();
    divisionOperator();
    matmulExample();
    transposeExample();
    getArrayElement();
    setArrayElement();
    findMinFullArray();
    findMaxColumns();
    findMeanRows();

    return 0;
}
