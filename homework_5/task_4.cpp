#include <iostream>

void	print_matrix_rows(int matrix[][3], int start_from, int rows, int cols)
{
	for (int i = start_from + 1; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << "\n";
	}
}

int	main(void)
{
	int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int rows = 3;
	int cols = 3;

	print_matrix_rows(matrix, 1, rows, cols);
	return (0);
}
