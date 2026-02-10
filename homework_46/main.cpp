#include <iostream>
#include <memory>   // just for comparison
#include <string>
#include "shared.hpp" // your rub::shared_ptr header

struct Foo
{
    int x;
    Foo(int x = 0) : x(x) { std::cout << "Foo(" << x << ") constructed\n"; }
    ~Foo() { std::cout << "Foo(" << x << ") destroyed\n"; }
    void hello() { std::cout << "Hello from Foo(" << x << ")\n"; }
};

struct Bar
{
    std::string s;
    Bar(std::string str = "") : s(str) { std::cout << "Bar(" << s << ") constructed\n"; }
    ~Bar() { std::cout << "Bar(" << s << ") destroyed\n"; }
};

struct MyDeleter
{
    void operator()(Foo* f) { std::cout << "Custom deleter called for Foo(" << f->x << ")\n"; delete f; }
};

int main()
{
    std::cout << "=== Default ctor ===\n";
    rub::shared_ptr<Foo> sp1;
    std::cout << "use_count: " << sp1.use_count() << "\n\n";

    std::cout << "=== nullptr ctor ===\n";
    rub::shared_ptr<Foo> sp2(nullptr);
    std::cout << "use_count: " << sp2.use_count() << "\n\n";

    std::cout << "=== Raw ptr ctor ===\n";
    rub::shared_ptr<Foo> sp3(new Foo(42));
    std::cout << "use_count: " << sp3.use_count() << "\n\n";

    std::cout << "=== Raw ptr + deleter ctor ===\n";
    rub::shared_ptr<Foo> sp4(new Foo(100), MyDeleter());
    std::cout << "use_count: " << sp4.use_count() << "\n\n";

    std::cout << "=== Copy ctor ===\n";
    rub::shared_ptr<Foo> sp5(sp3);
    std::cout << "sp3 use_count: " << sp3.use_count() << ", sp5 use_count: " << sp5.use_count() << "\n\n";

    std::cout << "=== Move ctor ===\n";
    rub::shared_ptr<Foo> sp6(std::move(sp3));
    std::cout << "sp3 use_count: " << sp3.use_count() << ", sp6 use_count: " << sp6.use_count() << "\n\n";

    std::cout << "=== Copy assignment ===\n";
    sp1 = sp5;
    std::cout << "sp1 use_count: " << sp1.use_count() << ", sp5 use_count: " << sp5.use_count() << "\n\n";

    std::cout << "=== Move assignment ===\n";
    sp2 = std::move(sp5);
    std::cout << "sp2 use_count: " << sp2.use_count() << ", sp5 use_count: " << sp5.use_count() << "\n\n";

    std::cout << "=== bool operator ===\n";
    if (sp2) std::cout << "sp2 is not null\n";
    if (!sp5) std::cout << "sp5 is null\n\n";

    std::cout << "=== operator* and operator-> ===\n";
    sp2->hello();
    (*sp2).hello();
    std::cout << "\n";

    std::cout << "=== reset() ===\n";
    sp2.reset();
    std::cout << "sp2 use_count: " << sp2.use_count() << "\n\n";

    std::cout << "=== swap() ===\n";
    rub::shared_ptr<Foo> sp7(new Foo(77));
    rub::shared_ptr<Foo> sp8(new Foo(88));
    std::cout << "Before swap: sp7=" << sp7.get() << ", sp8=" << sp8.get() << "\n";
    sp7.swap(sp8);
    std::cout << "After swap: sp7=" << sp7.get() << ", sp8=" << sp8.get() << "\n\n";

    std::cout << "=== get_deleter() ===\n";
    auto del = sp4.get_deleter<MyDeleter>();
    if (del) std::cout << "Got deleter\n\n";

    std::cout << "=== Array specialization ===\n";
    rub::shared_ptr<Foo[]> spArr1(new Foo[3]{ {1}, {2}, {3} });
    std::cout << "spArr1[0]: " << spArr1[0].x << ", spArr1[1]: " << spArr1[1].x << ", spArr1[2]: " << spArr1[2].x << "\n";
    rub::shared_ptr<Foo[]> spArr2(spArr1);
    std::cout << "spArr1 use_count: " << spArr1.use_count() << ", spArr2 use_count: " << spArr2.use_count() << "\n\n";

    std::cout << "=== Array operator= ===\n";
    rub::shared_ptr<Foo[]> spArr3;
    spArr3 = spArr1;
    std::cout << "spArr3 use_count: " << spArr3.use_count() << "\n\n";

    std::cout << "=== Array reset() ===\n";
    spArr3.reset();
    std::cout << "spArr3 use_count: " << spArr3.use_count() << "\n\n";

    std::cout << "=== Array swap() ===\n";
    rub::shared_ptr<Foo[]> spArr4(new Foo[2]{ {10}, {20} });
    rub::shared_ptr<Foo[]> spArr5(new Foo[2]{ {30}, {40} });
    spArr4.swap(spArr5);
    std::cout << "spArr4[0]: " << spArr4[0].x << ", spArr5[0]: " << spArr5[0].x << "\n\n";

    std::cout << "=== Everything going out of scope ===\n";
    return 0;
}
