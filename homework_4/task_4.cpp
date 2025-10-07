#include <iostream>

void	recursive_print(int count)
{
	if (count > 1)
		recursive_print(count - 1);
	std::cout << "Hello World\n";
}

int main()
{
	recursive_print(7);
	return (0);
}