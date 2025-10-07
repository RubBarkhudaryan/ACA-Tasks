#include <iostream>

void	print_matrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
}

int main()
{
	int	rows;
	int	cols;
	int	**matrix;

	std::cout << "rows: ";
	std::cin >> rows;
	std::cout << "cols: ";
	std::cin >> cols;

	matrix = new int *[rows];
	for (int i = 0; i < rows; ++i)
		matrix[i] = new int[cols];
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; ++j)
			std::cin >> matrix[i][j];
	}

	print_matrix(matrix, rows, cols);

	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
	return (0);
}