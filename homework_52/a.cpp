#include "./a.hpp"
#include <iostream>

A::A()
{}

A::~A()
{}

A&	A::get_instance()
{
	static A	singleton;
	return (singleton);
}

void	A::f()
{
	std::cout << "f called" << std::endl;
}