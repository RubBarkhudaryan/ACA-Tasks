#include <iostream>

void	free_matrix(int **matrix, int rows)
{
	std::cout << "For carefully deallocation check rerun program with valgring\n";
	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

void	print_matrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

int main()
{
	int	**matrix;
	int	rows;
	int	cols;

	std::cout << "rows = ";
	std::cin >> rows;

	std::cout << "cols = ";
	std::cin >> cols;

	matrix = new int *[rows];

	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cin >> matrix[i][j];
	}

	print_matrix(matrix, rows, cols);
	free_matrix(matrix, rows);

	return 0;
}