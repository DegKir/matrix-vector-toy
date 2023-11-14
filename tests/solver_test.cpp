#include<iostream>
#include"mathvector.h"
#include"matrix.h"
#include"solver.h"

int main()
{
    int TaskDim = 4;
    int iterationNum = 2;
    Matrix testOperator = getEyeMatrix(TaskDim);
    testOperator[0][0] = 5;
    testOperator[0][1] = 1;
    testOperator[0][2] = 1;
    testOperator[1][1] = 5;
    testOperator[1][2] = 4;
    testOperator[2][2] = 7;
    testOperator[3][3] = 2;
    
    
    MathVector trueSolution(TaskDim);
    trueSolution[0] = 1;
    trueSolution[1] = 2;
    trueSolution[2] = 3;
    trueSolution[3] = 4;
    MathVector rhs = testOperator.apply(trueSolution);
    MathVector solverSolution(TaskDim);
    std::cout << "operator is " << std::endl << testOperator;
    std::cout << "rhs is " << std::endl << rhs << std::endl;
    std::cout << "Solver will perform " << iterationNum << " iterations " << std::endl << std::endl;
    
    JacobiSolver solver;
    solverSolution = solver.solve(testOperator, rhs, iterationNum);
    MathVector difference = solverSolution - trueSolution;
    
    std::cout << "Calculated answer is " << solverSolution << std::endl;
    std::cout << "Real answer is " << trueSolution << std::endl;
    std::cout << "l2 norm of x-x_true = "<< difference.getEuclidNorm() << std::endl;
    
}
