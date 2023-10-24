#include <iostream>
#include "matrix.h"
Matrix::Matrix(int size) : size_(size) 
{
	values_ = new double *[size];
	
	
	for(int i = 0; i < size; i++)
	{
		values_[i] = new double [size];
	}

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			values_[i][j]=0.0;
		}
	//	std::cout<<"EERE"<<i<<std::endl;
		values_[i][i]=(double)i;
	}

//	for(int i = 0; i < size; i++)
//		values_[i,i]=i;

//	for(int i = 0; i < size; i++)
//		for(int j = 0; j < size; j++)
//			std::cout <<"["<<i<<"]"<<"["<<j<<"]"<< values_[i,j] << std::endl;

	std::cout << "Matrix created with size = " << size << std::endl;
}

Matrix::~Matrix()
{
	for(int i = 0; i < size_; i++)
		delete[] values_[i];
	delete[] values_;
}

int Matrix::getSize()
{
	return size_;
}

std::ostream & operator << (std::ostream & os, Matrix & matrix)
{
	for(int i = 0; i < matrix.size_; i++)
	{
		for(int j = 0; j < matrix.size_; j++)
		{
			os << matrix.values_[i][j] << " ";
		}
		os << std::endl;
	}
	return os;

}
