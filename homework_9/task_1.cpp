#include <iostream>

int	*init_arr(int size, int val)
{
	int	*arr;

	arr = new int[size]{val};
	return (arr);
}

int main()
{
	int	*arr;
	int	size;

	std::cout << "Size = ";
	std::cin >> size;

	arr = init_arr(size, 0);

	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";

	delete[] arr;
	return 0;
}