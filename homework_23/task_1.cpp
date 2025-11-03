#include "./matrix.h"

int main()
{
	Matrix mat1(2, 3);
	Matrix mat2(3, 2);

	std::cout << mat1 << "\n";
	std::cout << mat2 << "\n";
	std::cout << "mat1 * mat2\n" << mat1 * mat2;

	return (0);
}
