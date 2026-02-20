#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

std::recursive_mutex	mtx;

std::size_t	fibonacci(std::size_t num, std::vector<std::size_t>& memo)
{
	std::lock_guard<std::recursive_mutex>	lock(mtx);
	if (num <= 1)
		return (num);
	if (memo[num] != 0)
		return (memo[num]);
	memo[num] = fibonacci(num - 1, memo) + fibonacci(num - 2, memo);
	return (memo[num]);
}

int	main()
{
	std::size_t					idx;
	std::vector<std::size_t>	memo;

	std::size_t					idx_2;
	std::vector<std::size_t>	memo_2;

	idx = 5;
	memo.resize(idx + 1, 0);

	idx_2 = 200;
	memo_2.resize(idx_2 + 1, 0);

	std::thread	t1(fibonacci, idx, std::ref(memo));
	std::thread	t2(fibonacci, idx_2, std::ref(memo_2));

	t1.join();
	t2.join();

	std::cout << "fibonacci " << idx << " element: " << memo[idx] << std::endl;
	std::cout << "fibonacci " << idx_2 << " element: " << memo_2[idx_2] << std::endl;
	return (0);
}
