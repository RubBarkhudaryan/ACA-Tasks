#ifndef CHESSBOARD_H

#define CHESSBOARD_H

#include "./matrix.h"

class Chessboard : public Matrix
{
	public:
		/*Chessboard ctor/dtor*/
		Chessboard();
		~Chessboard() override;
		Chessboard(const Chessboard &other);
		Chessboard(Chessboard&& other) noexcept;

		/*Chessboard operators*/
		Chessboard& operator=(const Chessboard& other);
		Chessboard& operator=(Chessboard&& other) noexcept;

		/*Chessboard methods*/
		void	display() const override;
};

#endif // CHESSBOARD_H