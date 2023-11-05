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
    MathVector& operator [](int i);
    
	friend std::ostream & operator <<(std::ostream & os, Matrix & matrix);
    MathVector apply(MathVector & rhs);
};

Matrix getEyeMatrix(int size);
