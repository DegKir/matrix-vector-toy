#include<iostream>
#include"mathvector.h"
#include"matrix.h"
#include"solver.h"

int main()
{
    int TaskDim = 3;
    int iterationNum = 100;
    Matrix testOperator = getEyeMatrix(TaskDim);
    MathVector trueSolution = getOnes(TaskDim);
    MathVector rhs = testOperator.apply(trueSolution);
    MathVector solverSolution(TaskDim);
    
    std::cout << "Solver will perform "<< iterationNum << "iterations " << std::endl;
    
    ContractionMappingSolver solver;
    solverSolution = solver.solve(testOperator, rhs, iterationNum);
    MathVector difference = solverSolution - trueSolution;
    std::cout<<"l2 norm of x-x_true = "<< difference.getEuclidNorm() << std::endl;
}
