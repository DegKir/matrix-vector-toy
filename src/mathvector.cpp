#include <iostream>
#include <cmath>
#include "mathvector.h"

MathVector::MathVector(int size): size_(size)
{
    values_ = new double[size];
    for(int i = 0; i < size_; i++)
    {
        values_[i]=0;
    }
}

MathVector::MathVector()
{
    size_=0;
}

MathVector::MathVector(const MathVector &other)
{
    size_=other.size_;
    values_ = new double[size_];
    for(int i = 0; i < size_; i++)
    {
        values_[i]=other.values_[i];
    }
}

MathVector& MathVector::operator=(const MathVector &other) {
    if (this != &other)
    {
        if(size_ != 0)
            delete[] values_;

        size_ = other.size_;
        values_ = new double[size_];

        for (int i = 0; i < size_; i++)
        {
            values_[i] = other.values_[i];
        }
    }
    return *this;
}


MathVector::~MathVector()
{
    delete[] values_;
//    std::cout<<"Vector deleted"<<std::endl;
}

int MathVector::getSize()
{
    return size_;
}

double MathVector::getEuclidNorm()
{
    double sum = 0;
    for(int i = 0; i < size_; i++)
    {
        sum = sum + values_[i]*values_[i];
    }
    return std::sqrt(sum);
}

std::ostream & operator <<(std::ostream & os, MathVector & vector)
{
    for(int i = 0; i < vector.size_; i++)
    {
        os << vector.values_[i] << " ";
    }
    return os;
}

double& MathVector::operator[](int i)
{
    return values_[i];
}

MathVector operator+( MathVector &lhs,  MathVector &rhs)
{
    MathVector result(rhs.getSize());
    if(lhs.getSize() != rhs.getSize())
        std::cout << "ERROR" << std::endl;

    for(int i = 0; i < lhs.getSize(); i++)
    {
        result[i] = lhs[i] + rhs[i];
    }
    return result;
}

MathVector operator-( MathVector &lhs,  MathVector &rhs)
{
    MathVector result(lhs.getSize());
    if(lhs.getSize() != rhs.getSize())
        std::cout << "ERROR" << std::endl;

    for(int i = 0; i < lhs.getSize(); i++)
    {
        result[i] = lhs[i]-rhs[i];
    }
    return result;
}

MathVector operator*(double scalar, MathVector &vector)
{
    MathVector result(vector);
    for(int i = 0; i < result.getSize(); i++)
    {
        result[i] = scalar*vector[i];
    }
    return result;
    
}

double dot(MathVector &lhs, MathVector &rhs)
{
    if(lhs.getSize() != rhs.getSize())
        std::cout << "ERROR"<< std::endl;
    
    double sum = 0;
    for(int i = 0; i < lhs.getSize(); i++)
    {
        sum += lhs[i]*rhs[i];
    }
    return sum;
}

MathVector getUnitVector(int size, int coordinate)
{
    if(coordinate > size)
    {
        std::cout << "ERROR" <<std::endl;
    }
    MathVector result(size);
    result[coordinate] = 1;
    return result;
}

MathVector getOnes(int size)
{
    MathVector result(size);
    for(int i = 0; i < size; i++)
        result[i] = 1;
    return result;
}

