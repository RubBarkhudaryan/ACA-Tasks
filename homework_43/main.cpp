#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // for comparison
#include <cassert>
#include "./tools.h"

// ---------- TEST FUNCTORS ----------

struct Counter
{
	int count;

	Counter() : count(0) {}

	void operator()(int)
	{
		++count;
	}
};

struct Sum
{
	int total;

	Sum() : total(0) {}

	void operator()(int x)
	{
		total += x;
	}
};

void multiply_by_two(int &x)
{
	x *= 2;
}

// ---------- MAIN TEST ----------

int main()
{
	// 1️⃣ Lambda modifying elements
	{
		std::vector<int> v{1, 2, 3, 4};

		rub::for_each(v.begin(), v.end(), [](int &x) {
			x += 1;
		});

		assert((v == std::vector<int>{2, 3, 4, 5}));
	}

	// 2️⃣ Stateful functor (return value!)
	{
		std::vector<int> v{1, 2, 3, 4};

		Counter c = rub::for_each(v.begin(), v.end(), Counter{});
		assert(c.count == 4);
	}

	// 3️⃣ Accumulating functor
	{
		std::vector<int> v{1, 2, 3, 4};

		Sum s = rub::for_each(v.begin(), v.end(), Sum{});
		assert(s.total == 10);
	}

	// 4️⃣ Function pointer
	{
		std::vector<int> v{1, 2, 3};

		rub::for_each(v.begin(), v.end(), multiply_by_two);
		assert((v == std::vector<int>{2, 4, 6}));
	}

	// 5️⃣ Const iterator (read-only access)
	{
		const std::vector<int> v{1, 2, 3};
		int sum = 0;

		rub::for_each(v.begin(), v.end(), [&](int x) {
			sum += x;
		});

		assert(sum == 6);
	}

	// 6️⃣ Empty range
	{
		std::vector<int> v;

		Counter c = rub::for_each(v.begin(), v.end(), Counter{});
		assert(c.count == 0);
	}

	// 7️⃣ Different container (list)
	{
		std::list<int> l{1, 2, 3};

		int product = 1;
		rub::for_each(l.begin(), l.end(), [&](int x) {
			product *= x;
		});

		assert(product == 6);
	}

	// 8️⃣ Compare with std::for_each behavior
	{
		std::vector<int> v1{1, 2, 3};
		std::vector<int> v2{1, 2, 3};

		auto f1 = rub::for_each(v1.begin(), v1.end(), [](int &x) {
			x *= 3;
		});

		auto f2 = std::for_each(v2.begin(), v2.end(), [](int &x) {
			x *= 3;
		});

		assert(v1 == v2);
		(void)f1;
		(void)f2;
	}

	std::cout << "✅ All rub::for_each tests passed (STL-equivalent)\n";
	return 0;
}
