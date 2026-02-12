#include "./matrix.hpp"
#include <iostream>

int main()
{
	std::cout << "Creating 3x3 matrix A...\n";
	Matrix<int> A(3);

	// Fill A with values
	int val = 1;
	for (std::size_t i = 0; i < A.getRows(); ++i)
		for (std::size_t j = 0; j < A.getCols(); ++j)
			A[i][j] = val++;

	std::cout << "Matrix A:\n";
	A.display();

	std::cout << "Copy constructing B from A...\n";
	Matrix<int> B(A);
	std::cout << "Matrix B:\n";
	B.display();

	std::cout << "Move constructing C from B...\n";
	Matrix<int> C(std::move(B));
	std::cout << "Matrix C:\n";
	C.display();

	std::cout << "Transponate C...\n";
	C.transponate();
	std::cout << "Matrix C after transpose:\n";
	C.display();

	std::cout << "Sum A + C -> D\n";
	Matrix<int> D = A; 
	D.sum(C);
	D.display();

	std::cout << "Move assignment C = std::move(D)\n";
	C = std::move(D);
	std::cout << "Matrix C after move assignment:\n";
	C.display();

	return 0;
}