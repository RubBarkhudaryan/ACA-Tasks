#ifndef MATRIX_H

# define MATRIX_H

class	Matrix
{
	private:
		int	**matrix = nullptr;
		int	rows = 0;
		int	cols = 0;

	public:

		/* Matrix ctor/dtor */
		Matrix();
		Matrix(int rows);
		Matrix(int rows, int cols);
		Matrix(int rows, int cols, int **matrix);
		Matrix(const std::vector<std::string>& log_data);
		Matrix(const Matrix& matrix);
		~Matrix();

		/* Matrix operators */
		Matrix&					operator=(const Matrix& other);
		Matrix&					operator*(int num);
		Matrix&					operator*(const Matrix& other);
		Matrix&					operator++();
		Matrix					operator++(int);

		/* Matrix methods */
		void					print() const;
		void					transponate();
		int						getRows() const;
		int						getCols() const;
		int**					getMatrix() const;
		void					sum(const Matrix& other);
		friend std::ostream&	operator<<(std::ostream& os, const Matrix& matrix);

	/* Matrix helper functions */
	private:
		std::size_t					get_elem_count(const std::string& str);
		std::vector<std::string>	split(const std::string& str, char delimiter);
};

#endif