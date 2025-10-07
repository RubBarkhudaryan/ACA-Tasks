#include <iostream>

int main()
{
	int	arr[20];
	int	len = 20;

	for (int i = 0; i < len; ++i)
		arr[i] = rand() % 20;

	for (int i = 0; i < len; ++i)
		std::cout << arr[i] << " ";

	return (0);
}