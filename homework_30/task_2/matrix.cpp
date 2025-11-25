#include <iostream>
#include <ctime>
#include "matrix.h"

Matrix::Matrix()
{
	std::cout << "Matrix default ctor called.\n";
	rows = 0;
	cols = 0;
	matrix = nullptr;
}

Matrix::Matrix(int rows)
{
	std::srand(std::time(0));
	std::cout << "Matrix parameterized ctor called.\n";

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

Matrix::Matrix(int rows, int cols)
{
	std::srand(std::time(0));
	std::cout << "Matrix parameterized ctor called.\n";

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

Matrix::Matrix(int rows, int cols, int **matrix)
{
	std::cout << "Matrix parameterized ctor called.\n";
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

Matrix::Matrix(const Matrix& matrix)
{
	std::cout << "Matrix copy ctor called.\n";
	this->cols = matrix.cols;
	this->rows = matrix.rows;

	this->matrix = new int* [this->rows];

	for (int i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[this->cols];

	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix.matrix[i][j];
	}
}

Matrix::Matrix(Matrix&& matrix) noexcept
{
	std::cout << "Matrix move ctor called.\n";
	this->rows = matrix.rows;
	this->cols = matrix.cols;
	this->matrix = matrix.matrix;

	matrix.rows = 0;
	matrix.cols = 0;
	matrix.matrix = nullptr;
}

Matrix::~Matrix()
{
	std::cout << "Matrix dtor called.\n";
	for (int i = 0; i < this->rows; ++i)
		delete[] this->matrix[i];
	delete[] this->matrix;
}

Matrix&	Matrix::operator=(const Matrix& matrix)
{
	std::cout << "Matrix copy assignment operator called.\n";
	if (this != &matrix)
	{
		this->cols = matrix.cols;
		this->rows = matrix.rows;
		
		if (this->matrix)
		{
			for (int i = 0; i < rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;
		}

		this->matrix = new int* [this->rows];

		for (int i = 0; i < this->rows; ++i)
			this->matrix[i] = new int[this->cols];

		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->cols; ++j)
				this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
	return (*this);
}

Matrix&	Matrix::operator=(Matrix&& matrix) noexcept
{
	std::cout << "Matrix move assignment operator called.\n";
	if (this != &matrix)
	{
		if (this->matrix)
		{
			for (int i = 0; i < this->rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;
		}
		
		this->rows = matrix.rows;
		this->cols = matrix.cols;
		this->matrix = matrix.matrix;

		matrix.rows = 0;
		matrix.cols = 0;
		matrix.matrix = nullptr;
	}
	return (*this);
}

void	Matrix::display() const
{
	for (int i = 0; i < this->rows; ++i)
	{
		for (int j = 0; j < this->cols; ++j)
			std::cout << this->matrix[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	Matrix::transponate()
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

int	Matrix::getRows() const
{
	return (this->rows);
}

int	Matrix::getCols() const
{
	return (this->cols);
}

int**	Matrix::getMatrix() const
{
	return (this->matrix);
}

void	Matrix::sum(const Matrix& other)
{
	if (this->rows != other.rows || this->cols != other.cols)
		std::cout << "Rows/Cols of given matrix doesn't match\n";
	else
	{
		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->cols; ++j)
				this->matrix[i][j] += other.matrix[i][j];
		}
	}
}
