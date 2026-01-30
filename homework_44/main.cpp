#include <iostream>
#include <functional>

struct	F
{
	private:
		int	prod;
	public:
		F();
		~F() = default;
		F&						operator()(int num);
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

std::function<std::function<F (int)>()> closure = []() -> std::function<F (int)>
{
	F	f;
	return [f](int num) mutable
	{
		f(num);
		return (f);
	};
};

int main()
{
	F	f;
	std::function<F (int)> func = closure();
	std::cout << func(5)(6) << std::endl;
}
