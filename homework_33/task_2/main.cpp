#include <iostream>
#include <ctime>
#include "matrix.cpp"

int main()
{
	Matrix<double> mat_d(3);
	Matrix<int> mat_i(5);
	Matrix<int> mat_i_2(std::move(mat_i));

	if (mat_i.getMatrix() == nullptr)
		std::cout << "Matrix i: nullptr.\n";
	else
		mat_i.display();
	mat_d.display();
	mat_i_2.display();

	return (0);
}