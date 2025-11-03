#ifndef MATRIX_H

# define MATRIX_H
# include <iostream>
# include <ctime>

class	Matrix
{
	private:
		int	**matrix = nullptr;
		int	rows = 0;
		int	cols = 0;

	public:
		Matrix();
		Matrix(int rows);
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, int **matrix);
		Matrix(const Matrix& matrix);
		~Matrix();
		Matrix&					operator=(const Matrix& other);
		Matrix&					operator*(int num);
		Matrix&					operator*(const Matrix& other);
		Matrix&					operator++();
		Matrix					operator++(int);
		void					print();
		void					transponate();
		int						getRows() const;
		int						getCols() const;
		int**					getMatrix() const;
		void					sum(const Matrix& other);
		friend std::ostream&	operator<<(std::ostream& os, const Matrix& matrix);
};

#endif