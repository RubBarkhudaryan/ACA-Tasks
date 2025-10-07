#include <iostream>

int main(void)
{
	int	num1;
	int	num2;

	if (num1 < num2)
	{
		for (int i = num1; i < num2; ++i)
		{
			if (i % 2 == 1)
				std::cout << i << " ";
		}
	}
	else if (num2 < num1)
	{
		for (int i = num2; i < num1; ++i)
		{
			if (i % 2 == 1)
				std::cout << i << " ";
		}
	}
	else
		std::cout << "num1 == num2\n";

	return (0);
}