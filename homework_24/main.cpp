#include "matrix.h"

int main()
{
	std::cout << "\n--- Creating a 2x2 matrix of Cars ---\n";
	Matrix m1(2, 2);

	std::cout << "\n--- Filling matrix with custom Cars ---\n";
	Car **cars = m1.getMatrix();
	cars[0][0] = Car("Toyota", "Camry", "Blue", 2018);
	cars[0][1] = Car("BMW", "M3", "Black", 2021);
	cars[1][0] = Car("Audi", "A6", "White", 2019);
	cars[1][1] = Car("Tesla", "Model S", "Red", 2022);

	std::cout << "\n--- Printing Matrix (m1) ---\n";
	m1.print();

	std::cout << "\n--- Copy Constructing Matrix (m2 = m1) ---\n";
	Matrix m2 = m1;

	std::cout << "\n--- Repainting one car in m2 ---\n";
	m2.getMatrix()[0][0].repaint("Green");

	std::cout << "\n--- Printing Matrix (m1, should be unchanged) ---\n";
	m1.print();

	std::cout << "\n--- Printing Matrix (m2, should show repainted car) ---\n";
	m2.print();

	std::cout << "\n--- Testing Assignment Operator (m3 = m2) ---\n";
	Matrix m3;
	m3 = m2;

	std::cout << "\n--- Printing Matrix (m3) ---\n";
	m3.print();

	std::cout << "\n--- End of main, destructors will be called ---\n";

	return 0;
}
