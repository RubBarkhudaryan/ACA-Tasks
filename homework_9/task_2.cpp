#include <iostream>

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

int	**init_matrix(int rows, int cols)
{
	int	**matrix;

	matrix = new int *[rows];

	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols];

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			matrix[i][j] = i + j;
	}
	return (matrix);
}

int main()
{
	int	**matrix;
	int	rows;
	int	cols;

	std::cout << "Rows = ";
	std::cin >> rows;

	std::cout << "Cols = ";
	std::cin >> cols;

	matrix = init_matrix(rows, cols);

	print_matrix(matrix, rows, cols);

	return 0;
}