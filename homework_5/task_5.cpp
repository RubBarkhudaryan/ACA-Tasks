#include <iostream>
#include <vector>

bool	is_prime(int num)
{
	if (num < 2)
		return (false);
	for (int j = 2; j * j <= num; ++j)
	{
		if (num % j == 0)
			return (false);
	}
	return (true);
}

std::vector<int> prime_nums_arr(int matrix[][3], int rows, int cols)
{
	std::vector<int> prime_nums;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (is_prime(matrix[i][j]))
				prime_nums.push_back(matrix[i][j]);
		}
	}
	return (prime_nums)
}

int	main(void)
{
	int	matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int	rows;
	int	cols;

	rows = 3;
	cols = 3;
	std::vector<int> primes = prime_nums_arr(matrix, rows, cols);
	for (int i = 0; i < primes.size(); ++i)
		std::cout << primes[i] << " ";
	return (0);
}
