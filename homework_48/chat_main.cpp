#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>

void init_chunk(std::vector<short>& vec, std::size_t start, std::size_t end)
{
	for (std::size_t i = start; i < end; ++i)
		vec[i] = i % 100;  // simple write, fast
}

void sum_chunk(const std::vector<short>& vec, std::size_t start, std::size_t end, long long& result)
{
	result = std::accumulate(vec.begin() + start, vec.begin() + end, 0LL);
}

int main()
{
	constexpr std::size_t vec_size = 1000000000; // 1B elements (~2GB)
	std::vector<short> vec(vec_size);

	auto start = std::chrono::steady_clock::now();

	// Determine number of threads
	const unsigned num_threads = std::thread::hardware_concurrency(); 
	std::cout << "Using " << num_threads << " threads\n";

	const std::size_t chunk_size = vec_size / num_threads;

	// ------------------ INIT ------------------
	std::vector<std::thread> threads;
	for (unsigned i = 0; i < num_threads; ++i)
	{
		std::size_t start = i * chunk_size;
		std::size_t end = (i == num_threads - 1) ? vec_size : start + chunk_size;
		threads.emplace_back(init_chunk, std::ref(vec), start, end);
	}

	for (auto& t : threads) t.join();
	threads.clear();

	// ------------------ SUM ------------------
	std::vector<long long> partial_sums(num_threads, 0);

	for (unsigned i = 0; i < num_threads; ++i)
	{
		std::size_t start = i * chunk_size;
		std::size_t end = (i == num_threads - 1) ? vec_size : start + chunk_size;
		threads.emplace_back(sum_chunk, std::cref(vec), start, end, std::ref(partial_sums[i]));
	}

	for (auto& t : threads) t.join();

	// total sum
	long long total_sum = std::accumulate(partial_sums.begin(), partial_sums.end(), 0LL);

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> duration = end - start;

	std::cout << "Time: " << duration.count() << " seconds\n";

	std::cout << "Total sum: " << total_sum << "\n";
}
