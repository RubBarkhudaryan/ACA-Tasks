#include <iostream>

template <typename ...Args>
void	print(const Args& ... args)
{
	((std::cout << args << ' '), ...);
	std::cout << "\n";
}

int main()
{
	print(1, 2, 3, 5, "str");
}