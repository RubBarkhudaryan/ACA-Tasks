#ifndef A_HPP

# define A_HPP

class	A
{
	private:
		/*-----A ctor/dtor-----*/
		A();
		~A();

	public:
		/*-----A deleted ctor/dtor-----*/
		A(const A&) = delete;
		A(A&&) = delete;

		/*-----A deleted operators-----*/
		A&	operator=(const A&) = delete;
		A&	operator=(A&&) = delete;

		/*-----A methods-----*/
		static A&	get_instance();
		void		f();
};

#endif //A_HPP