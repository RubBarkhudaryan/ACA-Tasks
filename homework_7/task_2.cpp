#include <iostream>

void	print_max_elem_col_row(int **matrix, int rows, int cols)
{
	int	max;
	int	max_i;
	int	max_j;

	max = matrix[0][0];
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (max < matrix[i][j])
			{
				max = matrix[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}
	std::cout << "Max elem row: " << max_i << " Max elem col: " << max_j << "\n";
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

	print_max_elem_col_row(matrix, rows, cols);

	for (int i = 0; i < rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
	return (0);
}