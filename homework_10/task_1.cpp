#include <iostream>
#include <ctime>

double	avg(int *arr, int size)
{
	double	sum;

	if (size <= 0)
		return (0);
	else if (size == 1)
		return (arr[0]);

	sum = 0;
	for (int i = 0; i < size; ++i)
		sum += arr[i];

	return (sum / size);
}

int main()
{
	int	size;
	int	*arr;
	
	std::cout << "Size: ";
	std::cin >> size;
	srand(time(0));

	arr = new int[size];

	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 100;

	std::cout << "Avg = " << avg(arr, size) << "\n";
	delete[] arr;
	return (0);
}