#include <iostream>

int main(void)
{
	double	arr[10];
	double avg = 0;
	int	n;
	
	std::cout << "n = ";
	std::cin >> n;

	for (int i = 0; i < n; ++i)
		std::cin >> arr[i];

	for(int i = 0; i < n; ++i)
		avg += arr[i];

	avg /= n;

	for(int i = 0; i < n; ++i)
	{
		if (arr[i] > avg)
			std::cout << arr[i] << " ";
	}

	return (0);
}
