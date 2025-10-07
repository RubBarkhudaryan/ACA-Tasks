#include <iostream>

int	fibonacci(int num)
{
	if (num <= 1)
		return (num);
	return (fibonacci(num - 1) + fibonacci(num - 2));
}

int main()
{
	std::cout << "0-th = " << fibonacci(0) << "\n";
	std::cout << "3-rd = " << fibonacci(3) << "\n";
	std::cout << "5-th = " << fibonacci(5) << "\n";
	return (0);
}