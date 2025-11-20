#include <iostream>
#include <ctime>

class Matrix
{
	private:
		int	**matrix;
		int	rows;
		int	cols;

	public:
		Matrix()
		{
			std::cout << "Default ctor called.\n";
			rows = 0;
			cols = 0;
			matrix = nullptr;
		}

		Matrix(int rows)
		{
			std::srand(std::time(0));
			std::cout << "Parameterized ctor called.\n";

			this->rows = rows;
			this->cols = rows;
			this->matrix = new int* [rows];

			for (int i = 0; i < this->rows; ++i)
				this->matrix[i] = new int[rows];

			for (int i = 0; i < this->rows; ++i)
			{
				for (int j = 0; j < this->cols; ++j)
					this->matrix[i][j] = std::rand() % 100;
			}
		}

		Matrix(int rows, int cols)
		{
			std::srand(std::time(0));
			std::cout << "Parameterized ctor called.\n";

			this->rows = rows;
			this->cols = cols;
			this->matrix = new int* [rows];

			for (int i = 0; i < this->rows; ++i)
				this->matrix[i] = new int[cols];

			for (int i = 0; i < this->rows; ++i)
			{
				for (int j = 0; j < this->cols; ++j)
					this->matrix[i][j] = std::rand() % 100;
			}
		}

		Matrix(int rows, int cols, int **matrix)
		{
			std::cout << "Parameterized ctor called.\n";
			this->rows = rows;
			this->cols = cols;
			this->matrix = new int* [rows];

			for (int i = 0; i < this->rows; ++i)
				this->matrix[i] = new int[cols];
			
			for (int i = 0; i < this->rows; ++i)
			{
				for (int j = 0; j < this->cols; ++j)
					this->matrix[i][j] = matrix[i][j];
			}
		}

		~Matrix()
		{
			std::cout << "Dtor called.\n";
			for (std::size_t i = 0; i < this->rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;
		}

		void	print()
		{
			for (int i = 0; i < this->rows; ++i)
			{
				for (int j = 0; j < this->cols; ++j)
					std::cout << this->matrix[i][j] << " ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		void	transponate()
		{
			int	**new_matrix = new int* [this->cols];

			for (int i = 0; i < this->cols; ++i)
				new_matrix[i] = new int[rows]{0};

			for (int i = 0; i < this->cols; ++i)
			{
				for (int j = 0; j < this->rows; ++j)
					new_matrix[i][j] = this->matrix[j][i];
			}

			for (int i = 0; i < this->rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;

			this->matrix = new_matrix;
			std::swap(this->rows, this->cols);
		}

		int	getRows() const
		{
			return (this->rows);
		}

		int	getCols() const
		{
			return (this->cols);
		}

		int**	getMatrix() const
		{
			return (this->matrix);
		}

		void	sum(const Matrix& other)
		{
			if (this->rows != other.rows || this->cols != other.cols)
				std::cout << "Rows/Cols of given matrix doesn't match\n";
			else
			{
				for (std::size_t i = 0; i < this->rows; ++i)
				{
					for (std::size_t j = 0; j < this->cols; ++j)
						this->matrix[i][j] += other.matrix[i][j];
				}
			}
		}
};

int main()
{
	Matrix	mat1(3, 5);
	Matrix	mat2(5, 3);

	mat1.print();
	mat2.print();

	mat2.transponate();
	mat1.sum(mat2);

	mat1.print();
	mat2.print();
	return (0);
}