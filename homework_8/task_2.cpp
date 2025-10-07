#include <iostream>

unsigned long long	memo_fibonacci(unsigned long long num, unsigned long long *memo)
{
	if (num <= 1)
		return num;
	if (memo[num])
		return memo[num];
	memo[num] = memo_fibonacci(num - 1, memo) + memo_fibonacci(num - 2, memo);
	return memo[num];
}

int main()
{
	unsigned long long	num;
	unsigned long long	*memo;

	std::cout << "num = ";
	std::cin >> num;

	memo = new unsigned long long[num + 1];
	for (int i = 0; i <= num; ++i)
		std::cout << memo_fibonacci(i, memo) << " ";

	delete[] memo;
	return 0;
}