#include <iostream>

int main(void)
{
	int		num1;
	int		num2;
	char	oper;

	std::cout << "Num1: ";
	std::cin >> num1;

	std::cout << "Operator (+, -, *, /): ";
	std::cin >> oper;

	std::cout << "Num2: ";
	std::cin >> num2;

	if (oper == '+')
		std::cout << num1 << " + " << num2 << " = " << num1 + num2 << "\n";
	else if (oper == '-')
		std::cout << num1 << " - " << num2 << " = " << num1 - num2 << "\n";
	else if (oper == '*')
		std::cout << num1 << " * " << num2 << " = " << num1 * num2 << "\n";
	else if (oper == '/')
	{
		if (num2 != 0)
			std::cout << num1 << " / " << num2 << " = " << num1 / num2 << "\n";
		else
			std::cout << "Zero Division Error.\n";
	}
	else
		std::cout << "Invalid Operator.\n";
	return (0);
}
