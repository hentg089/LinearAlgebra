// LinAlg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
#include <memory>
#include "LinearAlgebra.h"

using namespace std;

int main()
{
    Matrix j(2, 1);
    j.inputData();
    j.print(19);
    LinearAlgebra::getHouseHolderVector(std::move(j), 1).print(3);







    

    
}


