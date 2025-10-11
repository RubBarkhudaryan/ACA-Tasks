#include "./header.hpp"

void	*ft_malloc(std::size_t size, std::string msg)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		std::cout << "Allocation failed.\n";
		return (NULL);
	}

	std::cout << "This is a safe malloc implementation.\n";
	if (msg != "")
		std::cout << "User message: " << msg << std::endl;
	return (ptr);
}

void	*operator new(std::size_t size)
{
	void	*ptr;
	ptr = ft_malloc(size, "");

	std::cout << "New operator call\n";
	return (ptr);
}

void	operator delete(void *ptr)
{
	std::cout << "Delete operator call\n";
	free(ptr);
}
