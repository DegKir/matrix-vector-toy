#pragma once
#include<iostream>
#include"mathvector.h"

class Matrix
{
	int size_;
	MathVector* rows_;
    
public:
	Matrix(int size);
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
	~Matrix();
	int getSize();
    Matrix getDiagonalMatrix();
    MathVector& operator [](int i);
    
	friend std::ostream & operator <<(std::ostream & os, Matrix & matrix);
    friend Matrix operator-( Matrix &lhs, Matrix &rhs);
    MathVector apply(MathVector & rhs);
};

Matrix getEyeMatrix(int size);
