#include <iostream>
#include <vector>

void swap_cols(std::vector<std::vector<int>>& mat, int c1, int c2)
{
	int n = mat.size();

	for (int i = 0; i < n; i++)
		std::swap(mat[i][c1], mat[i][c2]);
}

int main() {
	int	n;
	int	m;

	std::cin >> n >> m;
	std::vector<std::vector<int>> mat(n, std::vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cin >> mat[i][j];
	}

	int	c1;
	int	c2;
	std::cin >> c1 >> c2;

	swap_cols(mat, c1, c2);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << mat[i][j] << " ";
		std::cout << "\n";
	}
}
