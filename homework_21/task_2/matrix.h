#ifndef MATRIX_H

#define MATRIX_H

class Matrix
{
	private:
		int	**matrix;
		int	rows;
		int	cols;

	public:

		/*Matrix ctor/dtor*/
		Matrix();
		Matrix(int rows);
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, int **matrix);
		Matrix(const Matrix& matrix);
		~Matrix();

		/*Matrix operators*/
		Matrix&	operator=(const Matrix& matrix);

		/*Matrix methods*/
		void	print();
		void	transponate();
		int		getRows() const;
		int		getCols() const;
		int**	getMatrix() const;
		void	sum(const Matrix& other);
};

#endif	//MATRIX_H