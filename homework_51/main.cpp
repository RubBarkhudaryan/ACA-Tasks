#include <queue>
#include <mutex>
#include <thread>
#include <iostream>
#include <condition_variable>

struct	Storage
{
	int				storage_size;
	std::queue<int>	storage;

	Storage(int size);

	bool	is_full() const;
	bool	is_empty() const;
	void	pop();
	void	push(int i);
};

Storage					st(50);
std::mutex				mtx;
std::condition_variable	cv;

Storage::Storage(int size) : storage_size (size)
{}

bool	Storage::is_full() const
{
	return (this->storage_size == storage.size());
}

bool	Storage::is_empty() const
{
	return (this->storage.empty());
}

void	Storage::pop()
{
	this->storage.pop();
	std::cout << "Pop() storage size: " << this->storage.size() << std::endl;
}

void	Storage::push(int i)
{
	this->storage.push(i);
	std::cout << "Push() storage size: " << this->storage.size() << std::endl;
}

void	producer()
{
	while (true)
	{
		std::unique_lock	lock(mtx);
		cv.wait(lock, []{
			return (!st.is_full());
		});
		st.push(1);
		lock.unlock();
		cv.notify_one();
	}
}

void	consumer()
{
	while (true)
	{
		std::unique_lock	lock(mtx);
		cv.wait(lock, []{
			return (!st.is_empty());
		});
		st.pop();
		lock.unlock();
		cv.notify_one();
	}
}

int	main()
{
	std::thread	t1(producer);
	std::thread	t2(consumer);

	t1.join();
	t2.join();
	return (0);
}
