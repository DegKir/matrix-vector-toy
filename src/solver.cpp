#include "mathvector.h"
#include "matrix.h"
#include "solver.h"

SolverInterface::~SolverInterface() {}


MathVector ContractionMappingSolver::solve(Matrix &oper, MathVector &rhs, int iterationNum)
{
    int size = oper.getSize();
    MathVector x = getOnes(size);
    MathVector step;
    double stepCoef = 0.1;
    for(int i = 0; i < iterationNum; i++)
    {
        auto im = oper.apply(x);
        step = im - rhs;
        step = stepCoef*step;
        x = x + step;
    }
    
    return x;
}

ContractionMappingSolver::~ContractionMappingSolver() {}
