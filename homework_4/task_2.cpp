#include <iostream>

void	print_arr(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

int main()
{
	int	arr[20];
	int	len = 20;

	for (int i = 0; i < len; ++i)
		arr[i] = rand() % 20;

	print_arr(arr, len);

	return (0);
}