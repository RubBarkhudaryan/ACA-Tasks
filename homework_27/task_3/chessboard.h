#ifndef CHESSBOARD_H

#define CHESSBOARD_H

#include "./matrix.h"

class Chessboard : public Matrix
{
	public:
		/*Chessboard ctor/dtor*/
		Chessboard();
		~Chessboard() override;

		/*Chessboard methods*/
		void	display() const override;
};

#endif // CHESSBOARD_H