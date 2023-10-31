#include <iostream>
#include "mathvector.h"

MathVector::MathVector(int size): size_(size)
{
    values_ = new double[10];
    for(int i = 0; i < size_; i++)
    {
        values_[i]=0;
    }
    std::cout<<"Vector created"<<std::endl;
}

MathVector::~MathVector()
{
    delete[] values_;
    std::cout<<"Vector deleted"<<std::endl;
}

int MathVector::getSize()
{
    return size_;
}

std::ostream & operator <<(std::ostream & os, MathVector & vector)
{
    for(int i = 0; i < vector.size_; i++)
    {
        os << vector.values_[i] << " ";
    }
    return os;
}
