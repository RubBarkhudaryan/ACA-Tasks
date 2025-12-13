#include <iostream>
#include <string>
#include <stdexcept>
#include "vector.h"

static void print_state(const rub::vector<int>& v, const std::string& name)
{
	std::cout << name << " | size=" << v.size()
			<< " capacity=" << v.capacity()
			<< " empty=" << v.empty()
			<< " | data: ";

	for (std::size_t i = 0; i < v.size(); ++i)
		std::cout << v[i] << ' ';
	std::cout << '\n';
}

int main()
{
	std::cout << "===== DEFAULT CONSTRUCTOR =====\n";
	rub::vector<int> a;
	print_state(a, "a");

	std::cout << "\n===== SIZE CONSTRUCTOR =====\n";
	rub::vector<int> b(5);
	print_state(b, "b");

	std::cout << "\n===== SIZE + VALUE CONSTRUCTOR =====\n";
	rub::vector<int> c(4, 7);
	print_state(c, "c");

	std::cout << "\n===== INITIALIZER LIST CONSTRUCTOR =====\n";
	rub::vector<int> d{1, 2, 3, 4};
	print_state(d, "d");

	std::cout << "\n===== COPY CONSTRUCTOR =====\n";
	rub::vector<int> e(d);
	print_state(e, "e");

	std::cout << "\n===== MOVE CONSTRUCTOR =====\n";
	rub::vector<int> f(std::move(e));
	print_state(f, "f");
	print_state(e, "e (moved-from)");

	std::cout << "\n===== COPY ASSIGNMENT =====\n";
	a = f;
	print_state(a, "a");

	std::cout << "\n===== MOVE ASSIGNMENT =====\n";
	b = std::move(a);
	print_state(b, "b");
	print_state(a, "a (moved-from)");

	std::cout << "\n===== PUSH_BACK (COPY + MOVE) =====\n";
	rub::vector<std::string> s;
	std::string hello = "hello";

	s.push_back(hello);              // copy
	s.push_back(std::string("world"));// move
	s.push_back("!!!");              // move

	std::cout << "s | ";
	for (std::size_t i = 0; i < s.size(); ++i)
		std::cout << s[i] << ' ';
	std::cout << '\n';

	std::cout << "\n===== FRONT / BACK / DATA =====\n";
	std::cout << "front: " << d.front() << '\n';
	std::cout << "back : " << d.back() << '\n';
	std::cout << "data[1]: " << d.data()[1] << '\n';

	std::cout << "\n===== OPERATOR[] MODIFICATION =====\n";
	d[1] = 42;
	print_state(d, "d");

	std::cout << "\n===== AT() WITH EXCEPTION =====\n";
	try
	{
		std::cout << d.at(100) << '\n';
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << "caught exception: " << ex.what() << '\n';
	}

	std::cout << "\n===== POP_BACK =====\n";
	d.pop_back();
	print_state(d, "d");

	std::cout << "\n===== RESERVE =====\n";
	d.reserve(20);
	print_state(d, "d");

	std::cout << "\n===== RESIZE (GROW) =====\n";
	d.resize(10, 9);
	print_state(d, "d");

	std::cout << "\n===== RESIZE (SHRINK) =====\n";
	d.resize(3);
	print_state(d, "d");

	std::cout << "\n===== SHRINK_TO_FIT =====\n";
	d.shrink_to_fit();
	print_state(d, "d");

	std::cout << "\n===== CLEAR =====\n";
	d.clear();
	print_state(d, "d");

	std::cout << "\n===== COMPARISON OPERATORS =====\n";
	rub::vector<int> x{1, 2, 3};
	rub::vector<int> y{1, 2, 3};
	rub::vector<int> z{1, 2, 4};

	std::cout << "x == y : " << (x == y) << '\n';
	std::cout << "x != z : " << (x != z) << '\n';
	std::cout << "x <  z : " << (x < z)  << '\n';
	std::cout << "z >  x : " << (z > x)  << '\n';
	std::cout << "x <= y : " << (x <= y) << '\n';
	std::cout << "x >= y : " << (x >= y) << '\n';

	std::cout << "\n===== ALL TESTS FINISHED =====\n";
	return (0);
}
