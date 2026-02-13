#include <iostream>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include <execution>

void	init_chunk(std::vector<short> &vec, std::size_t start, std::size_t end)
{
	for (std::size_t i = start; i < end; ++i)
		vec[i] = (i + 1) % 100;
}

void	sum(const std::vector<short>& vec, std::size_t start, std::size_t end, long long& sum)
{
	sum = std::accumulate(vec.begin() + start, vec.begin() + end, 0LL);
}

int	main()
{
	constexpr std::size_t		vec_size = 1000000000;
	constexpr std::size_t		chunk_count = 5;
	constexpr std::size_t		chunk_size = vec_size / 5;

	std::vector<short>			vec(vec_size);
	std::vector<std::thread>	threads;

	long long					total_sum;

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
