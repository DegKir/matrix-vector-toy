#include <iostream>
#include "mathvector.h"
#include "matrix.h"

int main()
{
	Matrix matrix(3);
    std::cout << "MATRIX TEST" << std::endl;
    std::cout << matrix << std::endl;
    
    std::cout << "First row look :" << std::endl;
    MathVector vector(matrix[0]);
    std::cout << vector << std::endl;
    
    //std::cout << matrix[0] << std::endl; somehow error
    std::cout << "First element of first row look :" << std::endl;
    std::cout << matrix[0][0] <<std::endl;
    
    std::cout << "Identity matrix :" << std::endl;
    Matrix eye = getEyeMatrix(3);
    std::cout << eye << std::endl;
    
    std::cout << "Matrix-vector multiplication :" << std::endl;
    std::cout << "Identity matrix on unit vector :" <<std::endl;
    MathVector unit = getUnitVector(3, 0);
    unit = eye.apply(unit);
    std::cout << unit << std::endl;
	return 0;
}
