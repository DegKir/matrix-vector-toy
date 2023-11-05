#include<iostream>
#include"mathvector.h"

int main()
{
    MathVector vector(5);
    std::cout<<"\nTesting getSize() function :"<<std::endl;
    std::cout<<"Vector size is " << vector.getSize()<<std::endl;
    std::cout<<"\nTesting std::cout on vector :"<<std::endl;
    std::cout<<vector<<std::endl;

    std::cout<<"\nTesting [] operator : "<<std::endl;
    vector[0]=1;
    vector[1]=2;
    vector[2]=3;
    vector[3]=4;
    vector[4]=5;
    std::cout<<vector<<std::endl;
    std::cout<<"\nTesting + operator : "<<std::endl;
    MathVector sum(vector+vector);
    std::cout<<sum<<std::endl;
    
    std::cout<<"\nTesting - operator : "<<std::endl;
    MathVector diff(sum-vector);
    std::cout<<diff<<std::endl;
    
    std::cout<<"\nTesting dot operator : "<<std::endl;
    double superdot = dot(vector, vector);
    std::cout << superdot << std::endl;
    
    std::cout<<"\nTesting unit vector : "<<std::endl;
    MathVector unit = getUnitVector(3, 0);
    std::cout << unit << std::endl;
    
    std::cout<<"\nTesting scalar multiplication :"<<std::endl;
    std::cout<<"5 * unit vector "<<std::endl;
    unit = 5.0*unit;
    std::cout << unit << std::endl;
    
    unit = 0.2*unit;
    
    std::cout<<"\nTesting l2 norm :"<<std::endl;
    std::cout<<unit.getEuclidNorm()<<std::endl;
}
