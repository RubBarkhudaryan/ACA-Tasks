#include <iostream>

struct	F
{
	private:
		int	prod;
	public:
		F();
		~F() = default;
		F&	operator()(int num);
		friend std::ostream&	operator <<(std::ostream& os, const F& obj);
};

F::F() : prod(1)
{}

F&	F::operator()(int num)
{
	this->prod *= num;
	return (*this);
}

std::ostream&	operator <<(std::ostream& os, const F& obj)
{
	os << obj.prod << "\n";
	return (os);
}

int main()
{
	F	f;
	std::cout << f(5)(6) << std::endl;
}