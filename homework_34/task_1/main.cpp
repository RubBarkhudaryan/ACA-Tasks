#include <iostream>
#include <ctime>

template <std::size_t NUM>
struct Fibonacci
{
	static const std::size_t	value = Fibonacci<NUM - 1>::value + Fibonacci<NUM - 2>::value;
};

template <>
struct Fibonacci<0>
{
	static const std::size_t	value = 0;
};

template <>
struct Fibonacci<1>
{
	static const std::size_t	value = 1;
};

int main()
{
	std::cout << "Fibonacci " << 5 << "-th element " << Fibonacci<5>::value << "\n";
	return (0);
}
