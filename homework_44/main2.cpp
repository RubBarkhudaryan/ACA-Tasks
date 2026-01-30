#include <iostream>
#include <functional>

std::function<std::function<int (int)>(int)> closure = [](int num) -> std::function<int (int)>
{
	return [num](int num2) mutable
	{
		return (num * num2);
	};
};

int main()
{
	std::cout << closure(5)(6) << std::endl;
}

/*
std::function<std::function<int (int)>()> closure = []() -> std::function<int (int)>
{
	int	prod = 1;

	return [prod](int num) mutable
	{
		prod *= num;
		return (prod);
	};
};

int main()
{
	std::function<int (int)> f = closure();
	std::cout << f(5) << std::endl;
	std::cout << f(6) << std::endl;
}

// this alternative was built before.
*/