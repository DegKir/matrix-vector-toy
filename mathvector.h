#pragma once
#include<iostream>

class MathVector
{
    int size_;
	double* values_;
public:
    MathVector(int size);
    ~MathVector();
    int getSize();
    friend std::ostream & operator <<(std::ostream & os, MathVector & matrix);
};
