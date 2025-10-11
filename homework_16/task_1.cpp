#include "./header.hpp"

int main()
{
	std::srand(time(0));
	int	*ptr;

	ptr = new int[10];

	for (int i = 0; i < 10; ++i)
		ptr[i] = std::rand() % 100;

	for (int i = 0; i < 10; ++i)
		std::cout << ptr[i] << " ";
	std::cout << std::endl;

	delete[] ptr;
	return (0);
}
