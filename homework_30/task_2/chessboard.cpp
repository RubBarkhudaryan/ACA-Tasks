#include <iostream>
#include "./chessboard.h"

Chessboard::Chessboard() : Matrix(8, 8)
{
	std::cout << "Chessboard ctor called.\n";
}

Chessboard::Chessboard(const Chessboard& other) : Matrix(other)
{
	std::cout << "Chessboard copy ctor called.\n";
}

Chessboard::Chessboard(Chessboard&& other) noexcept : Matrix(std::move(other))
{
	std::cout << "Chessboard move ctor called.\n";
}

Chessboard::~Chessboard()
{
	std::cout << "Chessboard dtor called.\n";
}

Chessboard&	Chessboard::operator=(const Chessboard& other)
{
	std::cout << "Chessboard copy assignment operator called.\n";
	if (this != &other)
	{
		if (this->matrix)
		{
			for (int i = 0; i < this->rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;
		}

		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = new int* [this->rows];

		for (int i = 0; i < this->rows; ++i)
			this->matrix[i] = new int[this->cols];
		for (int i = 0; i < this->rows; ++i)
		{
			for (int j = 0; j < this->cols; ++j)
				this->matrix[i][j] = other.matrix[i][j];
		}
	}
	return (*this);
}

Chessboard&	Chessboard::operator=(Chessboard&& other) noexcept
{
	std::cout << "Chessboard move assignment operator called.\n";
	if (this != &other)
	{
		if (this->matrix)
		{
			for (int i = 0; i < this->rows; ++i)
				delete[] this->matrix[i];
			delete[] this->matrix;
		}

		this->rows = other.rows;
		this->cols = other.cols;
		this->matrix = other.matrix;

		other.rows = 0;
		other.cols = 0;
		other.matrix = nullptr;
	}
	return (*this);
}

void	Chessboard::display() const
{
	std::cout << "   a   b   c   d   e   f   g   h \n";
	std::cout << " +-------------------------------+\n";
	for (int i = 0; i < this->rows; ++i)
	{
		std::cout << i + 1 << "|";
		for (int j = 0; j < this->cols; ++j)
		{
			if (j < this->cols - 1)
			{
				if ((i + j + 1) % 2 == 0)
					std::cout << u8"\u2B1C  ";
				else
					std::cout << u8"\u2B1B  ";
			}
			else
			{
				if ((i + j + 1) % 2 == 0)
					std::cout << u8"\u2B1C ";
				else
					std::cout << u8"\u2B1B ";
			}
		}
		std::cout << "|" << i + 1 << std::endl;
		if (i == this->rows - 1)
			break ;
		std::cout << " |" << std::string(30, ' ')  << " |" << std::endl;
	}
	std::cout << " +-------------------------------+\n";
	std::cout << "   a   b   c   d   e   f   g   h \n";
}
