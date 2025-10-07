#include <iostream>

int	factorial(int num)
{
	if (num <= 0)
		return (1);
	return (num * factorial(num - 1));
}

int main()
{
	std::cout << "(-1)! = " << factorial(-1) << "\n";
	std::cout << "0! = " << factorial(0) << "\n";
	std::cout << "3! = " << factorial(3) << "\n";
	std::cout << "5! = " << factorial(5) << "\n";
	return (0);
}