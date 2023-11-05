#include <iostream>
#include "matrix.h"
#include "mathvector.h"

Matrix::Matrix(int size) : size_(size)
{
    rows_ = new MathVector[size];
    for(int i = 0; i < size_; i++)
    {
        rows_[i] = MathVector(size_);
    }
}

Matrix::Matrix(const Matrix& other)
{
    size_ = other.size_;
    rows_ = new MathVector[size_];
    for(int i = 0; i < size_; i++)
    {
        rows_[i] = other.rows_[i];
    }
}

Matrix& Matrix::operator=(const Matrix &other)
{
    if (this != &other)
    {

        delete[] rows_;
        
        size_ = other.size_;
        rows_ = new MathVector[size_];

        for (int i = 0; i < size_; i++)
        {
            rows_[i] = other.rows_[i];
        }
    }
    return *this;
}

Matrix::~Matrix()
{
    delete[] rows_; // Deallocate the array of MathVector pointers
}


int Matrix::getSize()
{
	return size_;
}


std::ostream & operator << (std::ostream & os, Matrix & matrix)
{
	for(int i = 0; i < matrix.size_; i++)
	{
        os << matrix.rows_[i] << std::endl;
    }
	return os;
}

MathVector& Matrix::operator [](int i)
{
    return rows_[i];
}

MathVector Matrix::apply( MathVector & rhs)
{
    if(size_ != rhs.getSize())
        std::cout << "ERROR"<< std::endl;
    
    MathVector result(size_);
    
    
    for(int i = 0; i < size_; i++)
    {
        result[i] = dot(rows_[i], rhs);
    }
    
    return result;
}

Matrix getEyeMatrix(int size)
{
    Matrix result(size);
    for(int i = 0; i < size; i++)
    {
        result[i][i] = 1;
    }
    
    return result;
}
