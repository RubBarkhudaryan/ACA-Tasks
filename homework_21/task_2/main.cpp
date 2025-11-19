#include <iostream>
#include <ctime>
#include "matrix.h"

int main()
{
	Matrix	mat1(3, 5);
	Matrix	mat2(5, 3);

	mat1.print();
	mat2.print();

	mat2.transponate();
	mat1.sum(mat2);

	mat1.print();
	mat2.print();
	return (0);
}