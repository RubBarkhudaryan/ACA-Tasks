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