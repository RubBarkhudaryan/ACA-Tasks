#include <iostream>

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

int main(int argc, char **argv)
{
	int	res;

	fibonacci_ref(atoi(argv[1]), res);
	std::cout << res << "\n";
}