#pragma once
#include<iostream>

class MathVector
{
    int size_;
	double* values_;
public:
    MathVector(int size);
    MathVector();

    MathVector(const MathVector &other);
    MathVector& operator=(const MathVector &other);

    ~MathVector();
    int getSize();
    double getEuclidNorm();
    double& operator [](int i);
    friend std::ostream & operator <<(std::ostream & os, MathVector & vector);
    friend double dot(MathVector &lhs, MathVector &rhs);
    friend MathVector operator+( MathVector &lhs,  MathVector &rhs);
    friend MathVector operator-( MathVector &lhs,  MathVector &rhs);
    friend MathVector operator*( double scalar, MathVector &vector);
    
};

MathVector getUnitVector(int size, int coordinate);
MathVector getOnes(int size);
