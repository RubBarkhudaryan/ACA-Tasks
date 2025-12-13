#ifndef MATRIX_H

#define MATRIX_H

template <typename T>
class Matrix
{
	protected:
		T			**matrix = nullptr;
		std::size_t	rows = 0;
		std::size_t	cols = 0;

	public:
		/*Matrix ctor/dtor*/
		Matrix();
		Matrix(std::size_t rows);
		Matrix(std::size_t rows, std::size_t cols);
		Matrix(std::size_t rows, std::size_t cols, T **matrix);
		Matrix(const Matrix<T>& matrix);
		Matrix(Matrix<T>&& other);
		virtual ~Matrix();

		/*Matrix operators*/
		Matrix<T>&		operator=(const Matrix<T>& matrix);
		Matrix<T>&		operator=(Matrix<T>&& matrix);

		/*Matrix methods*/
		virtual void	display() const;
		void			transponate();
		std::size_t		getRows() const;
		std::size_t		getCols() const;
		T**				getMatrix() const;
		void			sum(const Matrix<T>& other);
};

#endif	//MATRIX_H