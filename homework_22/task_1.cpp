#include <iostream>
#include <ctime>

class Matrix
{
	private:
		int	**matrix = nullptr;
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

			for (std::size_t i = 0; i < this->rows; ++i)
				this->matrix[i] = new int[rows];

			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
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

			for (std::size_t i = 0; i < this->rows; ++i)
				this->matrix[i] = new int[cols];

			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
					this->matrix[i][j] = std::rand() % 100;
			}
		}

		Matrix(int rows, int cols, int **matrix)
		{
			std::cout << "Parameterized ctor called.\n";
			this->rows = rows;
			this->cols = cols;
			this->matrix = matrix;
		}

		Matrix(const Matrix& matrix)
		{
			std::cout << "Matrix copy ctor called.\n";
			if (this->matrix)
			{
				for (std::size_t i = 0; i < rows; ++i)
					delete[] this->matrix[i];
				delete[] this->matrix;
			}

			this->cols = matrix.cols;
			this->rows = matrix.rows;
			this->matrix = new int* [this->rows];

			for (std::size_t i = 0; i < this->rows; ++i)
				this->matrix[i] = new int[this->cols];
			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
					this->matrix[i][j] = matrix.matrix[i][j];
			}
		}

		Matrix& operator=(const Matrix& matrix)
		{
			std::cout << "Assignment opertor called.\n";
			if (this != &matrix)
			{
				std::cout << "Deep copy.\n";
				this->cols = matrix.cols;
				this->rows = matrix.rows;
				if (this->matrix)
				{
					for (std::size_t i = 0; i < rows; ++i)
						delete[] this->matrix[i];
					delete[] this->matrix;
				}

				this->cols = matrix.cols;
				this->rows = matrix.rows;
				this->matrix = new int* [this->rows];

				for (std::size_t i = 0; i < this->rows; ++i)
					this->matrix[i] = new int[this->cols];
				for (std::size_t i = 0; i < this->rows; ++i)
				{
					for (std::size_t j = 0; j < this->cols; ++j)
						this->matrix[i][j] = matrix.matrix[i][j];
				}
			}
			return *this;
		}

		Matrix&	operator*(int num)
		{
			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
					this->matrix[i][j] *= num;
			}
			return *this;
		}

		Matrix&	operator++()
		{
			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
					++(this->matrix[i][j]);
			}
			return *this;
		}

		Matrix	operator++(int)
		{
			Matrix	temp = *this;

			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
					++(this->matrix[i][j]);
			}
			return temp;
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
			for (std::size_t i = 0; i < this->rows; ++i)
			{
				for (std::size_t j = 0; j < this->cols; ++j)
					std::cout << this->matrix[i][j] << " ";
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}

		void	transponate()
		{
			int	**new_matrix = new int* [this->cols];

			for (std::size_t i = 0; i < this->cols; ++i)
				new_matrix[i] = new int[rows]{0};

			for (std::size_t i = 0; i < this->cols; ++i)
			{
				for (std::size_t j = 0; j < this->rows; ++j)
					new_matrix[i][j] = this->matrix[j][i];
			}

			for (std::size_t i = 0; i < this->rows; ++i)
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
				std::cout << "Rows/Cols of given matrix doesn't match.\n";
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
	Matrix mat(3, 3);

	std::cout << "Matrix before operator *.\n";
	mat.print();

	std::cout << "Matrix after operator *.\n";
	mat = mat * 3;
	mat.print();

	std::cout << "Matrix before pre increment.\n";
	mat.print();

	std::cout << "Matrix after pre increment.\n";
	++mat;
	mat.print();

	std::cout << "Matrix before post increment.\n";
	Matrix mat2 = mat++;
	mat2.print();

	std::cout << "Matrix after post increment.\n";
	mat.print();
	return (0);
}