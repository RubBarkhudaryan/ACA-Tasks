#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <execution>
#include <random>

void	init_chunk(std::vector<short> &vec, std::size_t start, std::size_t end)
{
	std::random_device						rand;
	std::mt19937							gen(rand());
	std::uniform_int_distribution<short>	dist(0, 100);

	for (std::size_t i = start; i < end; ++i)
		vec[i] = dist(gen);
}

void	sum(const std::vector<short>& vec, std::size_t start, std::size_t end, long long& sum)
{
	sum = std::reduce(std::execution::par, vec.begin() + start, vec.begin() + end, 0LL);
}

int	main()
{
	constexpr std::size_t		vec_size = 1000000000;
	std::size_t					chunk_count = std::thread::hardware_concurrency();
	std::size_t					chunk_size = vec_size / chunk_count;

	std::vector<short>			vec(vec_size);
	std::vector<std::thread>	threads;

	long long					total_sum;

	std::cout << "Threads count: " << chunk_count << std::endl;
	std::cout << "Chunk size: " << chunk_size << std::endl;

	auto start = std::chrono::steady_clock::now();

	for (std::size_t i = 0; i < chunk_count; ++i)
	{
		std::size_t	start = i * chunk_size;
		std::size_t	end = (i == chunk_count - 1) ? vec_size : start + chunk_size;
		threads.emplace_back(init_chunk, std::ref(vec), start, end);
	}

	for (auto &thread : threads)
		thread.join();
	threads.clear();

	std::vector<long long>		partial_sum(chunk_count, 0);

	for (std::size_t i = 0; i < chunk_count; ++i)
	{
		std::size_t	start = i * chunk_size;
		std::size_t	end = (i == chunk_count - 1) ? vec_size : start + chunk_size;
		threads.emplace_back(sum, std::cref(vec), start, end, std::ref(partial_sum[i]));
	}

	for (auto &thread : threads)
		thread.join();
	threads.clear();

	total_sum = 0;

	for (auto elem : partial_sum)
		total_sum += elem;

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> duration = end - start;

	std::cout << "Time: " << duration.count() << " seconds\n";

	std::cout << "Total sum: " << total_sum << "\n";

	return (0);
}
