#include <iostream>

int main(void)
{
	int	arr[10];
	int	n;

	std::cout << "n = ";
	std::cin >> n;
	
	for (int i = 0; i < n; ++i)
		arr[i] = rand() % 10;
	
	int	input_num;

	std::cout << "Insert num for search: ";
	std::cin >> input_num;

	for(int i = 0; i < n; ++i)
	{
		if (arr[i] == input_num)
			std::cout << i << " ";
	}

	return (0);
}
