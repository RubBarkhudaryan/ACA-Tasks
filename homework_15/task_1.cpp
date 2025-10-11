#include "./header.hpp"

void	*operator new(std::size_t size)
{
	void	*ptr;
	ptr = malloc(size);

	if (!ptr)
		std::cout << "Allocation fail\n";
	std::cout << "New operator call\n";
	return (ptr);
}

void	operator delete(void *ptr)
{
	std::cout << "Delete operator call\n";
	free(ptr);
}
