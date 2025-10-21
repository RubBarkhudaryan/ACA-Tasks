#include <iostream>
#include <ctime>

void	init_matrix(int ***matrix, int rows, int cols)
{
	*matrix = (int **)malloc(sizeof(int *) * rows);
	if (!(*matrix))
	{
		std::cout << "Allocation fail\n";
		return;
	}
	for (int i = 0; i < rows; ++i)
	{
		(*matrix)[i] = (int *)malloc(sizeof(int) * cols);
		if (!(*matrix)[i])
		{
			std::cout << "Allocation fail\n";
			return;
		}
		for (int j = 0; j < cols; ++j)
			(*matrix)[i][j] = std::rand() % 100;
	}
}

void	print_matrix(int **matrix, int rows, int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			std::cout << matrix[i][j] << " ";
		std::cout << std::endl;
	}
}

int	main(int argc, char **argv)
{
	std::srand(time(0));

	if (argc == 3)
	{
		int	rows;
		int	cols;
		int	**matrix;

		rows = atoi(argv[1]);
		cols = atoi(argv[2]);

		if (rows <= 0 || cols <= 0)
			std::cout << "Rows and cols must be greater than 0.\n";
		else
		{
			init_matrix(&matrix, rows, cols);
			print_matrix(matrix, rows, cols);

			for (int i = 0; i < rows; ++i)
				free(matrix[i]);
			free(matrix);
		}
	}
	else
		std::cout << "Wrong args count. Run program like this -> ./a.out 2 2. Last two args need to be numeric args.\n";
	return (0);
}
