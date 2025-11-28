#include <iostream>
#include "a.h"

int main()
{
	A	obj1;

	{
		A	obj2;
		A	obj3;
	}

	A	obj4;
	A	arr[5];
	A	*obj5 = new A();

	delete obj5;
	return (0);
}