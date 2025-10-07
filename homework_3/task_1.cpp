#include <iostream>

int main(void)
{
	int	arr[10];
	int	n = 10;
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 10;
	
	int	max = arr[0];
	int	min = arr[0];

	for(int i = 1; i < n; ++i)
	{
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
	}

	std::cout << "Max: " << max << " Min: " << min << "\n";
	return (0);
}
