#include <iostream>
#include <ctime>
#include "matrix.h"

template <typename T>
Matrix<T>::Matrix()
{
	std::cout << "Matrix default ctor called.\n";
	rows = 0;
	cols = 0;
	matrix = nullptr;
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows)
{
	std::cout << "Matrix parameterized ctor called.\n";

	this->rows = rows;
	this->cols = rows;
	this->matrix = new T* [rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new T[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = T();
	}
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
{
	std::cout << "Matrix parameterized ctor called.\n";

	this->rows = rows;
	this->cols = cols;
	this->matrix = new T* [rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new T[cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = T();
	}
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols, T **matrix)
{
	std::cout << "Matrix parameterized ctor called.\n";
	this->rows = rows;
	this->cols = cols;
	this->matrix = new T* [rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new T[cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix[i][j];
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix& matrix)
{
	std::cout << "Matrix copy ctor called.\n";
	this->cols = matrix.cols;
	this->rows = matrix.rows;

	if (this->matrix)
	{
		for (std::size_t i = 0; i < rows; ++i)
			delete[] this->matrix[i];
		delete[] this->matrix;
	}

	this->matrix = new T* [this->rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new T[this->cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix.matrix[i][j];
	}
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other)
{
	std::cout << "Matrix move ctor called.\n";
	this->rows = other.rows;
	this->cols = other.cols;
	this->matrix = other.matrix;

	other.matrix = nullptr;
	other.rows = 0;
	other.cols = 0;
}

template <typename T>
Matrix<T>::~Matrix()
{
	std::cout << "Matrix dtor called.\n";
	for (std::size_t i = 0; i < this->rows; ++i)
		delete[] this->matrix[i];
	delete[] this->matrix;
}

template <typename T>
Matrix<T>&	Matrix<T>::operator=(const Matrix<T>& matrix)
{
	std::cout << "Matrix assignment opertor called.\n";
	if (this != &matrix)
	{
		this->cols = matrix.cols;
		this->rows = matrix.rows;

		if (this->matrix)
		{
			for (std::size_t i = 0; i < rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;
		}

		this->matrix = new T* [this->rows];

		for (std::size_t i = 0; i < this->rows; ++i)
			this->matrix[i] = new T[this->cols];

		for (std::size_t i = 0; i < this->rows; ++i)
		{
			for (std::size_t j = 0; j < this->cols; ++j)
				this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
	return (*this);
}

template <typename T>
Matrix<T>&	Matrix<T>::operator=(Matrix<T>&& other)
{
	std::cout << "Matrix move assignment operator called.\n";
	if (this != *other)
	{
		for (std::size_t i = 0; i < this->rows; ++i)
			delete[] this->matrix[i];
		delete[] matrix;

		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = other.matrix;

		other.matrix = nullptr;
		other.rows = 0;
		other.cols = 0;
	}
	return (*this);
}

template <typename T>
void	Matrix<T>::display() const
{
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			std::cout << this->matrix[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void	Matrix<T>::transponate()
{
	T	**new_matrix = new T* [this->cols];

	for (std::size_t i = 0; i < this->cols; ++i)
		new_matrix[i] = new T[rows]{0};

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

template <typename T>
std::size_t	Matrix<T>::getRows() const
{
	return (this->rows);
}

template <typename T>
std::size_t	Matrix<T>::getCols() const
{
	return (this->cols);
}

template <typename T>
T**	Matrix<T>::getMatrix() const
{
	return (this->matrix);
}

template <typename T>
void	Matrix<T>::sum(const Matrix<T>& other)
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
