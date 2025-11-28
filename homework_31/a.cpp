#include <iostream>
#include "a.h"

int A::count = 0;

A::A()
{
	count++;
	std::cout << "A class ctor called. Current count: " << count << std::endl;
}

A::~A()
{
	count--;
	std::cout << "A class dtor called. Current count: " << count << std::endl;
}
