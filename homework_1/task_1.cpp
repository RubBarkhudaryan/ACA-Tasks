#include <iostream>

int main(void)
{
	float	num1;
	float	num2;
	float	num3;

	float	avg;

	std::cin >> num1 >> num2 >> num3;
	avg = (num1 + num2 + num3) / 3;
	std::cout << "Avg: " << avg << std::endl;

	return (0);
}