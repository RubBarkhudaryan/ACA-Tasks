#include <iostream>

void	free_matrix(int **matrix, int rows)
{
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

int	**transponate_matrix(int **matrix, int row, int col)
{
	int	**new_matrix;

	new_matrix = new int *[col];

	for (int i = 0; i < col; ++i)
		new_matrix[i] = new int[row];

	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
			new_matrix[i][j] = matrix[j][i];
	}

	return new_matrix;
}

int main()
{
	int	**matrix;
	int	**transponated;
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

	transponated = transponate_matrix(matrix, rows, cols);

	print_matrix(matrix, rows, cols);
	print_matrix(transponated, cols, rows);

	free_matrix(matrix, rows);
	free_matrix(transponated, cols);

	return 0;
}