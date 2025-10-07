#include "header.hpp"

int main(int argc, char **argv)
{
	int	fib;
	int	fact;

	fibonacci_ref(atoi(argv[1]), fib);
	std::cout << fib << "\n";

	factorial_ref(atoi(argv[1]), fact);
	std::cout << fact << "\n";
}