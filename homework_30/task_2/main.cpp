#include <iostream>
#include <ctime>
#include "chessboard.h"

int main()
{
	Chessboard	chessboard1;
	Chessboard	chessboard2 = std::move(chessboard1);
	Chessboard	chessboard3;

	chessboard3 = chessboard1;
	std::cout << "Chessboard 1:\n";
	chessboard1.display();
	std::cout << "\n\nChessboard 2 (moved from Chessboard 1):\n";
	chessboard2.display();
	std::cout << "\n\nChessboard 3 (after assignment from Chessboard 1):\n";
	chessboard3.display();
	chessboard3 = chessboard2;
	std::cout << "\n\nChessboard 3 (after copy assignment from Chessboard 2):\n";
	chessboard3.display();
	return (0);
}