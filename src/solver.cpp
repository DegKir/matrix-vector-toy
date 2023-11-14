#include "mathvector.h"
#include "matrix.h"
#include "solver.h"

SolverInterface::~SolverInterface() {}


MathVector ContractionMappingSolver::solve(Matrix &oper, MathVector &rhs, int iterationNum)
{
    int size = oper.getSize();
    MathVector x = getOnes(size);
    MathVector step, im;
    double stepCoef = 0.01;
    for(int i = 0; i < iterationNum; i++)
    {
        im = oper.apply(x);
        step = im - rhs;
        step = stepCoef*step;
        x = x + step;
    }
    
    return x;
}

ContractionMappingSolver::~ContractionMappingSolver() {}

MathVector JacobiSolver::solve(Matrix &oper, MathVector &rhs, int iterationNum)
{
    int size = oper.getSize();
    MathVector x = getOnes(size);
    Matrix D = oper.getDiagonalMatrix();
    Matrix DInv(size);
    Matrix LpU(size);
    
    for(int i = 0; i < size; i++)
    {
        DInv[i][i]=1.0/D[i][i];
    }
    
    LpU = oper - D;
    
    for(int i = 0; i < iterationNum; i++)
    {
        auto tmp = LpU.apply(x);
        tmp = rhs-tmp;
        x = DInv.apply(tmp);
    }
    
    return x;
}

JacobiSolver::~JacobiSolver() {}
