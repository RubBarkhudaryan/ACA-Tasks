#include "./matrix.h"

Matrix::Matrix()
{
	std::cout << "Default ctor called.\n";
	this->rows = 0;
	this->cols = 0;
	this->matrix = nullptr;
}

Matrix::Matrix(int rows)
{
	std::srand(std::time(0));
	std::cout << "Parameterized ctor called.\n";

	this->rows = rows;
	this->cols = rows;
	this->matrix = new Car *[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new Car[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j];
	}
}

Matrix::Matrix(int rows, int cols)
{
	std::srand(std::time(0));
	std::cout << "Parameterized ctor called.\n";

	this->rows = rows;
	this->cols = cols;
	this->matrix = new Car *[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new Car[cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j];
	}
}

Matrix::Matrix(int rows, int cols, Car **matrix)
{
	std::cout << "Parameterized ctor called.\n";
	this->rows = rows;
	this->cols = cols;
	this->matrix = new Car *[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new Car[cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix[i][j];
	}
}

Matrix::Matrix(const Matrix &matrix)
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
	this->matrix = new Car *[this->rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new Car[this->cols];
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix.matrix[i][j];
	}
}

Matrix&	Matrix::operator=(const Matrix &matrix)
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
		this->matrix = new Car *[this->rows];

		for (std::size_t i = 0; i < this->rows; ++i)
			this->matrix[i] = new Car[this->cols];
		for (std::size_t i = 0; i < this->rows; ++i)
		{
			for (std::size_t j = 0; j < this->cols; ++j)
				this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
	return *this;
}

Car&	Matrix::operator[](std::size_t index) const
{
	return *matrix[index];
}

Matrix::~Matrix()
{
	std::cout << "Dtor called.\n";
	for (std::size_t i = 0; i < this->rows; ++i)
		delete[] this->matrix[i];
	delete[] this->matrix;
}

void	Matrix::print()
{
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			std::cout << this->matrix[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int	Matrix::getRows() const
{
	return (this->rows);
}

int	Matrix::getCols() const
{
	return (this->cols);
}

Car**	Matrix::getMatrix() const
{
	return (this->matrix);
}

std::ostream&	operator<<(std::ostream& os, const Matrix& matrix)
{
	for (std::size_t i = 0; i < matrix.rows; ++i)
	{
		for (std::size_t j = 0; j < matrix.cols; ++j)
			os << matrix.matrix[i][j] << " ";
		os << std::endl;
	}
	return os;
}
