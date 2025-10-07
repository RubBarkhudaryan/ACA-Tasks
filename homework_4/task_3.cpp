#include <iostream>

void	print_arr(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void	print_max_prod(int arr1[], int len1, int arr2[], int len2)
{
	int	prod1 = 1;
	int	prod2 = 1;

	for (int i = 0; i < len1; ++i)
		prod1 *= arr1[i];

	for (int i = 0; i < len2; ++i)
		prod2 *= arr2[i];

	if (prod1 > prod2)
	{
		std::cout << "Max Prod - prod1: " << prod1 << "\n";
		print_arr(arr1, len1);
	}
	else if (prod2 > prod1)
	{
		std::cout << "Max Prod - prod2: " << prod2 << "\n";
		print_arr(arr2, len2);
	}
	else
	{
		std::cout << "Prod1 == Prod2: " << prod1 << "\n";
		print_arr(arr1, len1);
	}
}

int main()
{
	int	arr1[20];
	int	arr2[20];
	int	len = 20;

	for (int i = 0; i < len; ++i)
	{
		arr1[i] = rand() % 20;
		arr2[i] = rand() % 20;
	}

	print_max_prod(arr1, len, arr2, len);

	return (0);
}