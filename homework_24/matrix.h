#ifndef MATRIX_H

# define MATRIX_H
# include <iostream>
# include <ctime>
# include "./car.h"

class	Matrix
{
	private:
		Car	**matrix = nullptr;
		int	rows = 0;
		int	cols = 0;

	public:
		Matrix();
		Matrix(int rows);
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, Car **matrix);
		Matrix(const Matrix& matrix);
		~Matrix();
		Matrix&					operator=(const Matrix& other);
		Car&					operator[](std::size_t index) const;
		void					print();
		int						getRows() const;
		int						getCols() const;
		Car**					getMatrix() const;
		friend std::ostream&	operator<<(std::ostream& os, const Matrix& matrix);
};

#endif