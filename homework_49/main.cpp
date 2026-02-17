#include <iostream>
#include <vector>
#include <numeric>
#include <future>
#include <chrono>

long long sum_chunk(const std::vector<int>& vec, std::size_t start, std::size_t end)
{
	return std::accumulate(vec.begin() + start, vec.begin() + end, 0LL);
}

int main()
{
	constexpr std::size_t vec_size = 1000000000;
	std::vector<int> vec(vec_size);

	for (std::size_t i = 0; i < vec_size; ++i)
		vec[i] = i % 100;

	const unsigned num_threads = std::thread::hardware_concurrency();
	const std::size_t chunk_size = vec_size / num_threads;

	std::vector<std::future<long long>> futures;

	auto start_time = std::chrono::steady_clock::now();

	for (unsigned i = 0; i < num_threads; ++i)
	{
		std::size_t start = i * chunk_size;
		std::size_t end = (i == num_threads - 1) ? vec_size : start + chunk_size;

		futures.push_back(
			std::async(std::launch::async, sum_chunk, std::cref(vec), start,end)
		);
	}

	long long total_sum = 0;
	for (auto& f : futures)
		total_sum += f.get();

	auto end_time = std::chrono::steady_clock::now();

	std::cout << "Total sum: " << total_sum << "\n";
	std::cout << "Time: " << std::chrono::duration<double>(end_time - start_time).count() << " seconds\n";
}