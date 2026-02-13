#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <execution>

void	init_vector(std::vector<char> &vec, std::size_t start, std::size_t end)
{
	for (std::size_t i = start; i < end; ++i)
		vec[i] = (i + 1) % 100;
}

int	main()
{
	std::srand(std::time(0));

	constexpr std::size_t	vec_size = 1000000000;
	constexpr std::size_t	chunk_size = vec_size / 5; // 200 000 000

	std::vector<char>	vec(vec_size);

	long long	total_sum;

	auto start = std::chrono::steady_clock::now();

	std::thread	init_thread_1(init_vector, std::ref(vec), 0, chunk_size);						// [0, 199 999 999]
	std::thread	init_thread_2(init_vector, std::ref(vec), chunk_size, chunk_size * 2);			// [200 000 000, 399 999 999]
	std::thread	init_thread_3(init_vector, std::ref(vec), chunk_size * 2, chunk_size * 3);		// [400 000 000, 599 999 999]
	std::thread	init_thread_4(init_vector, std::ref(vec), chunk_size * 3, chunk_size * 4);		// [600 000 000, 799 999 999]
	std::thread	init_thread_5(init_vector, std::ref(vec), chunk_size * 4, vec_size);			// [800 000 000, 999 999 999]

	init_thread_1.join();
	init_thread_2.join();
	init_thread_3.join();
	init_thread_4.join();
	init_thread_5.join();

	total_sum = std::reduce(std::execution::par, vec.begin(), vec.end(), 0LL);

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> duration = end - start;

	std::cout << "Time: " << duration.count() << " seconds\n";

	std::cout << "Total sum: " << total_sum << "\n";

	return (0);
}
