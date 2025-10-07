#include <iostream>
#include <ctime>

void	avg(int *arr, int size, double *avg)
{
	double	sum;

	if (size <= 0)
		*avg = 0;
	else if (size == 1)
		*avg = arr[0];
	else
	{
		sum = 0;
		for (int i = 0; i < size; ++i)
			sum += arr[i];
	
		*avg = (sum / size);
	}
}

int main()
{
	int		size;
	int		*arr;
	double	avg_;
	
	std::cout << "Size: ";
	std::cin >> size;
	srand(time(0));

	arr = new int[size];

	for (int i = 0; i < size; ++i)
		arr[i] = rand() % 100;

	avg(arr, size, &avg_);
	std::cout << "Avg = " << avg_ << "\n";
	delete[] arr;
	return (0);
}