#include <iostream>
#include "./chessboard.h"

Chessboard::Chessboard() : Matrix(8, 8)
{
	std::cout << "Chessboard ctor called.\n";
}

Chessboard::~Chessboard()
{
	std::cout << "Chessboard dtor called.\n";
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
