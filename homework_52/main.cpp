#include "./a.hpp"

int	main()
{
	A&	obj = A::get_instance();

	obj.f();

	return (0);
}