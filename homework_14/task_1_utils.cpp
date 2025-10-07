#include "header.hpp"

void	fibonacci_ref(int n, int& res)
{
	int	curr;
	int	prev;

	prev = 0;
	curr = 1;
	for (int i = 1; i < n; ++i)
	{
		res = (curr + prev);
		prev = curr;
		curr = res;
	}
}

void	factorial_ref(int n, int& res)
{
	if (n <= 1)
		res = 1;
	else
	{
		res = 1;
		for (int i = 1; i <= n; ++i)
			res *= i;
	}
}
