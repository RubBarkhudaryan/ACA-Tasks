#ifndef MATRIX_HPP

# define MATRIX_HPP

# include "./unique.hpp"

template <typename T>
class	Matrix
{
	private:
		std::size_t				rows;
		std::size_t				cols;
		rub::unique_ptr<rub::unique_ptr<T[]>[]>	data;

	public:
		/*Matrix ctor/dtor*/
		Matrix();
		Matrix(std::size_t rows);
		Matrix(std::size_t rows, std::size_t cols);
		Matrix(std::size_t rows, std::size_t cols, const rub::unique_ptr<rub::unique_ptr<T[]>[]>& matrix);
		Matrix(const Matrix<T>& matrix);
		Matrix(Matrix<T>&& matrix) noexcept;
		~Matrix() = default;

		/*Matrix operators*/
		rub::unique_ptr<T[]>&	operator[](std::size_t ind) const;
		Matrix<T>&				operator=(const Matrix<T>& other);
		Matrix<T>&				operator=(Matrix<T>&& other) noexcept;

		/*Matrix methods*/
		void											display() const;
		void											transponate();
		std::size_t										getRows() const;
		std::size_t										getCols() const;
		rub::unique_ptr<rub::unique_ptr<T[]>[]>			getMatrix() const;
		void											sum(const Matrix<T>& other);
};

# include "./matrix.tpp"

#endif	//MATRIX_HPP