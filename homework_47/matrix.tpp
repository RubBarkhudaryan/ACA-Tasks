#ifndef MATRIX_TPP

# define MATRIX_TPP

# include <iostream>
# include "./matrix.hpp"


template <typename T>
Matrix<T>::Matrix() : rows(0), cols(0), data(nullptr)
{
	std::cout << "Matrix default ctor called.\n";
}


template <typename T>
Matrix<T>::Matrix(std::size_t rows) :
	rows(rows),
	cols(rows),
	data(rub::unique_ptr<rub::unique_ptr<T[]>[]>(new rub::unique_ptr<T[]>[this->rows]))
{
	std::cout << "Matrix parameterized ctor called.\n";

	for (std::size_t i = 0; i < this->rows; i++)
		this->data[i] = rub::unique_ptr<T[]>(new T[this->cols]);

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->data[i][j] = T{};
	}
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols) :
	rows(rows),
	cols(cols),
	data(rub::unique_ptr<rub::unique_ptr<T[]>[]>(new rub::unique_ptr<T[]>[this->rows]))
{
	for (std::size_t i = 0; i < this->rows; i++)
		this->data[i] = rub::unique_ptr<T[]>(new T[this->cols]);

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->data[i][j] = T{};
	}
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const rub::unique_ptr<rub::unique_ptr<T[]>[]>& matrix) :
	rows(rows),
	cols(cols),
	data(rub::unique_ptr<rub::unique_ptr<T[]>[]>(new rub::unique_ptr<T[]>[this->rows]))
{
	std::cout << "Matrix parameterized ctor called.\n";

	for (std::size_t i = 0; i < this->rows; i++)
		this->data[i] = rub::unique_ptr<T[]>(new T[this->cols]);

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->data[i][j] = matrix[i][j];
	}
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) :
	rows(other.rows),
	cols(other.cols),
	data(rub::unique_ptr<rub::unique_ptr<T[]>[]>(new rub::unique_ptr<T[]>[this->rows]))
{
	std::cout << "Matrix copy ctor called.\n";

	for (std::size_t i = 0; i < this->rows; i++)
		this->data[i] = rub::unique_ptr<T[]>(new T[this->cols]);

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			this->data[i][j] = other.data[i][j];
	}
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept :
	rows(other.rows),
	cols(other.cols),
	data(std::move(other.data))
{
	std::cout << "Matrix move ctor called.\n";

	other.rows = 0;
	other.cols = 0;
}

template <typename T>
rub::unique_ptr<T[]>&	Matrix<T>::operator[](std::size_t ind) const
{
	return (this->data[ind]);
}

template <typename T>
Matrix<T>&	Matrix<T>::operator=(const Matrix<T>& other)
{
	std::cout << "Matrix copy assignment operator called.\n";
	if (this != &other)
	{
		this->rows = other.rows;
		this->cols = other.cols;

		this->data = rub::unique_ptr<rub::unique_ptr<T[]>[]>(new rub::unique_ptr<T[]>[this->rows]);

		for (int i = 0; i < this->rows; ++i)
			this->data[i] = rub::unique_ptr<T[]>(new T[this->cols]);

		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->cols; ++j)
				this->data[i][j] = other.data[i][j];
		}
	}
	return (*this);
}

template <typename T>
Matrix<T>&	Matrix<T>::operator=(Matrix<T>&& other) noexcept
{
	std::cout << "Matrix move assignment operator called.\n";
	if (this != &other)
	{
		this->rows = other.rows;
		this->cols = other.cols;
		this->data = std::move(other.data);

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
			std::cout << this->data[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
void	Matrix<T>::transponate()
{
	rub::unique_ptr<rub::unique_ptr<T[]>[]>	new_data(new rub::unique_ptr<T[]>[this->cols]);

	for (std::size_t i = 0; i < this->cols; ++i)
		new_data[i] = rub::unique_ptr<T[]>(new T[this->rows]);

	for (std::size_t i = 0; i < this->cols; ++i)
	{
		for (std::size_t j = 0; j < this->rows; ++j)
			new_data[i][j] = this->data[j][i];
	}

	this->data = std::move(new_data);
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
rub::unique_ptr<rub::unique_ptr<T[]>[]>	Matrix<T>::getMatrix() const
{
	rub::unique_ptr<rub::unique_ptr<T[]>[]>	temp(new rub::unique_ptr<T[]>[this->rows]);

	for (std::size_t i = 0; i < this->rows; ++i)
		temp[i] = rub::unique_ptr<T[]>(new T[this->cols]);

	for (std::size_t i = 0; i < this->rows; ++i)
	{
		for (std::size_t j = 0; j < this->cols; ++j)
			temp[i][j] = this->data[i][j];
	}
	return (temp);
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
				this->data[i][j] += other.data[i][j];
		}
	}
}

#endif //MATRIX_TPP