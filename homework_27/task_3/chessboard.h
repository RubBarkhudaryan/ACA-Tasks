#ifndef CHESSBOARD_H

#define CHESSBOARD_H

#include "./matrix.h"

class Chessboard : public Matrix
{
	public:
		Chessboard();
		~Chessboard() override;

		void	display() const override;
};

#endif // CHESSBOARD_H