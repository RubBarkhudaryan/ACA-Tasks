#include "./a.hpp"
#include <iostream>

int	main()
{
	A&	obj = A::get_instance();

	obj.f();

	return (0);
}