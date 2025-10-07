#include <iostream>

int	*init_arr(int size)
{
	int	*arr;

	arr = new int[size]{};
	return (arr);
}

void	print_max_arr(int *arr1, int size1, int *arr2, int size2)
{
	int	sum1 = 0;
	int	sum2 = 0;

	for (int i = 0; i < size1; ++i)
		sum1 += arr1[i];
	for (int i = 0; i < size2; ++i)
		sum2 += arr2[i];
	if (sum1 > sum2)
	{
		std::cout << "Sum1 > Sum2\n";
		for (int i = 0; i < size1; ++i)
			std::cout << arr1[i] << " ";
		std::cout << "\n";
	}
	else if (sum2 > sum1)
	{
		std::cout << "Sum2 > Sum1\n";
		for (int i = 0; i < size2; ++i)
			std::cout << arr2[i] << " ";
		std::cout << "\n";
	}
	else
	{
		std::cout << "Sum1 == Sum2\n";
		for (int i = 0; i < size2; ++i)
			std::cout << arr2[i] << " ";
		std::cout << "\n";
	}
}

int main()
{
	int	*arr1;
	int	*arr2;

	int	size1;
	int	size2;

	std::cout << "Size1 = ";
	std::cin >> size1;

	std::cout << "Size2 = ";
	std::cin >> size2;

	arr1 = init_arr(size1);
	arr2 = init_arr(size2);

	print_max_arr(arr1, size1, arr2, size2);

	delete[] arr1;
	delete[] arr2;

	return 0;
}