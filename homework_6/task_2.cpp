#include <iostream>
#include <vector>

void transpose(std::vector<std::vector<int>>& mat)
{
	int n = mat.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
			std::swap(mat[i][j], mat[j][i]);
	}
}

int main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> mat(n, std::vector<int>(n));

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			std::cin >> mat[i][j];

	transpose(mat);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
			std::cout << mat[i][j] << " ";
		std::cout << "\n";
	}
}
