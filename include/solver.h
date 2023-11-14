#pragma once
#include "mathvector.h"
#include "matrix.h"

class SolverInterface
{
public:
    virtual MathVector solve(Matrix &oper, MathVector &rhs, int iterationNum) = 0;
    virtual ~SolverInterface() = 0;
};

class ContractionMappingSolver : public SolverInterface
{
public:
    MathVector solve(Matrix &oper, MathVector &rhs, int iterationNum) override;
    ~ContractionMappingSolver();
};

class JacobiSolver : public SolverInterface
{
public:
    MathVector solve(Matrix &oper, MathVector &rhs, int iterationNum) override;
    ~JacobiSolver();
};
