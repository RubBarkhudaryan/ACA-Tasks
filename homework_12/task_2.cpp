#include <iostream>

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

int main(int argc, char **argv)
{
	int	res;

	factorial_ref(atoi(argv[1]), res);
	std::cout << res << "\n";
}