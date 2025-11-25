#ifndef MATRIX_H

#define MATRIX_H

class Matrix
{
	protected:
		int	**matrix = nullptr;
		int	rows = 0;
		int	cols = 0;

	public:
		/*Matrix ctor/dtor*/
		Matrix();
		Matrix(int rows);
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, int **matrix);
		Matrix(const Matrix& matrix);
		Matrix(Matrix&& matrix) noexcept;
		virtual ~Matrix();

		/*Matrix operators*/
		Matrix&			operator=(const Matrix& matrix);
		Matrix&			operator=(Matrix&& matrix) noexcept;

		/*Matrix methods*/
		virtual void	display() const;
		void			transponate();
		int				getRows() const;
		int				getCols() const;
		int**			getMatrix() const;
		void			sum(const Matrix& other);
};

#endif	//MATRIX_H