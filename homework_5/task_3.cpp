#include <iostream>
#include <vector>

std::size_t	fibonacci(std::size_t num, std::vector<std::size_t>& memo)
{
	if (num <= 1)
		return (num);
	if (memo[num] != -1)
		return memo[num];
	memo[num] = fibonacci(num - 1, memo) + fibonacci(num - 2, memo);
	return memo[num];
}

int main()
{
	std::size_t					n = 100;
	std::vector<std::size_t>	memo(n + 1, -1);

	std::cout << "100-th : " << fibonacci(n, memo) << "\n";
	return (0);
}