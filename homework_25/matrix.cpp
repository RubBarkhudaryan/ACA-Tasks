#include <iostream>
#include <vector>
#include <ctime>
#include <string.h>
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
	this->matrix = new int *[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = std::rand() % 100;
	}
}

Matrix::Matrix(int rows, int cols)
{
	std::srand(std::time(0));
	std::cout << "Parameterized ctor called.\n";

	this->rows = rows;
	this->cols = cols;
	this->matrix = new int *[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = std::rand() % 100;
	}
}

Matrix::Matrix(int rows, int cols, int **matrix)
{
	std::cout << "Parameterized ctor called.\n";
	this->rows = rows;
	this->cols = cols;
	this->matrix = new int *[rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix[i][j];
	}
}

Matrix::Matrix(const Matrix& matrix)
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
	this->matrix = new int *[this->rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[this->cols];
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = matrix.matrix[i][j];
	}
}

Matrix::Matrix(const std::vector<std::string>& log_data)
{
	this->rows = 0;
	while (log_data[this->rows] != "")
		++this->rows;
	this->cols = get_elem_count(log_data[0]);
	this->matrix = new int* [this->rows];

	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[this->cols];

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		std::vector<std::string> row = split(log_data[i], ' ');
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] = std::stoi(row[j]);
	}
}

Matrix&	Matrix::operator=(const Matrix& matrix)
{
	std::cout << "Assignment opertor called.\n";
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

		this->cols = matrix.cols;
		this->rows = matrix.rows;
		this->matrix = new int *[this->rows];

		for (std::size_t i = 0; i < this->rows; ++i)
			this->matrix[i] = new int[this->cols];
		for (std::size_t i = 0; i < this->rows; ++i)
		{
			for (std::size_t j = 0; j < this->cols; ++j)
				this->matrix[i][j] = matrix.matrix[i][j];
		}
	}
	return (*this);
}

Matrix&	Matrix::operator*(int num)
{
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->matrix[i][j] *= num;
	}
	return (*this);
}

Matrix&	Matrix::operator*(const Matrix& other)
{
	if (this->cols != other.rows)
	{
		std::cout << "Can't multiplicate matrices. The count of cols in first matrix isn't equal to rows in second matrix.\n";
		return (*this);
	}

	Matrix	temp = *this;

	for (std::size_t i = 0; i < this->rows; ++i)
		delete[] this->matrix[i];
	delete[] this->matrix;

	this->matrix = new int*[this->rows];
	for (std::size_t i = 0; i < this->rows; ++i)
		this->matrix[i] = new int[other.cols];

	this->cols = other.cols;

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
		{
			this->matrix[i][j] = 0;
			for (std::size_t k = 0; k < temp.cols; ++k)
				this->matrix[i][j] += temp.matrix[i][k] * other.matrix[k][j];
		}
	}
	return (*this);
}

Matrix&	Matrix::operator++()
{
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			++(this->matrix[i][j]);
	}
	return (*this);
}

Matrix	Matrix::operator++(int)
{
	Matrix temp = *this;

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			++(this->matrix[i][j]);
	}
	return (temp);
}

Matrix::~Matrix()
{
	std::cout << "Dtor called.\n";
	for (std::size_t i = 0; i < this->rows; ++i)
		delete[] this->matrix[i];
	delete[] this->matrix;
}

void	Matrix::print() const
{
	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			std::cout << this->matrix[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void	Matrix::transponate()
{
	int **new_matrix = new int *[this->cols];

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

std::ostream&	operator<<(std::ostream& os, const Matrix& matrix)
{
	for (std::size_t i = 0; i < matrix.rows; ++i)
	{
		for (std::size_t j = 0; j < matrix.cols; ++j)
			os << matrix.matrix[i][j] << " ";
		os << std::endl;
	}
	return (os);
}

/*Matrix utils*/
std::size_t	Matrix::get_elem_count(const std::string& str)
{
	std::size_t	count = 0;

	for (std::size_t i = 0; i < str.size(); ++i)
	{
		int j = 0;
		while (str[i + j] >= '0' && str[i + j] <= '9')
			++j;
		if (j > 0)
		{
			++count;
			i += j;
		}
	}
	return (count);
}

std::vector<std::string>	Matrix::split(const std::string& str, char delimiter)
{
	std::vector<std::string>	split_arr;

	for (std::size_t i = 0; i < str.size(); ++i)
	{
		int j = 0;
		std::string tmp = "";
		while (str[i + j] != delimiter)
		{
			tmp += str[i + j];
			++j;
		}
		if (tmp != "")
		{
			i += j;
			split_arr.push_back(tmp);
		}
	}
	return (split_arr);
}
