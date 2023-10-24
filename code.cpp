#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct mydata
{
	int id;
	float value;
};

class myclass
{
	int *p;
public:
	myclass(int);
	~myclass();
	int getval() {return *p;}

};

myclass::myclass(int i )
{
	p = new int;
	if(!p) exit(1);
	*p = i;
}

myclass::~myclass() {delete p;}

void display(myclass & object) {cout << object.getval()<<"\n";}

int main()
{
	myclass a(10);
	display(a);
	return 0;
}	
