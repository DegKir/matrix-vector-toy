#pragma once
#include<iostream>

class Matrix
{
	int size_;
	double** values_;
public:
	Matrix(int size);
	~Matrix();
	int getSize();
	friend std::ostream & operator <<(std::ostream & os, Matrix & matrix);
};
