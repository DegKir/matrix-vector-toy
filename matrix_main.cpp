#include <iostream>
#include "matrix.h"

int main()
{
	Matrix myFunnyMatrix(10);
	std::cout<< myFunnyMatrix.getSize() << std::endl;
	std::cout<<"and here is the matrix :"<<std::endl;
	std::cout<<myFunnyMatrix<<std::endl;
	return 0;
}
