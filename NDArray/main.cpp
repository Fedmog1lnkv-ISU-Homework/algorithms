#include <iostream>
#include "NDArray.h"
#include "ExampleFunctions.hpp"

int main()
{
    NDArray arr1 = defaultConstructor();
    NDArray arr2 = zerosExample();
    NDArray arr3 = onesExample();
    NDArray arr4 = randomExample();
    NDArray arr5 = additionOperator();
    NDArray arr6 = subtractionOperator();
    NDArray arr7 = multiplicationOperator();
    NDArray arr8 = divisionOperator();
    NDArray arr9 = matmulExample();
    NDArray arr10 = transposeExample();
    float element = getArrayElement();
    element++;
    NDArray arr11 = setArrayElement();
    return 0;
}
