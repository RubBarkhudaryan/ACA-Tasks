#include <iostream>

int main(void)
{
	int	n;
	int	factorial;

	std::cout << "n = ";
	std::cin >> n;

	factorial = 1;
	if (n > 1)
	{
		for (int i = 1; i <= n; ++i)
			factorial *= i;
	}

	std::cout << "Factorial: " << factorial << "\n";

	return (0);
}