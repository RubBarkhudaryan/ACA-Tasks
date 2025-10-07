#include <iostream>

#define MIN(a, b) ((a) > (b) ? b : a)

int main()
{
	int	num1;
	int	num2;

	std::cout << "num1: ";
	std::cin >> num1;

	std::cout << "num2: ";
	std::cin >> num2;

	std::cout << "Min: " << MIN(num1, num2) << std::endl;
}
