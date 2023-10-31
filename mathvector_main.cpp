#include<iostream>
#include"mathvector.h"

int main()
{
    MathVector vevector(5);
    std::cout<<"Testing getSize function :"<<std::endl;
    std::cout<<"Vector size is " << vevector.getSize()<<std::endl;
    std::cout<<"Testing std::cout on vector :"<<std::endl;
    std::cout<<vevector<<std::endl;
    std::cout<<"Testing destructor on vector :"<<std::endl;
}
