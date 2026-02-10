#include <iostream>
#include <memory>
#include "./shared.hpp"
#include "../homework_45/unique.hpp"

struct Base
{
    int x;
    Base(int v) : x(v) { std::cout << "Base(" << x << ") constructed\n"; }
    virtual ~Base() { std::cout << "Base(" << x << ") destroyed\n"; }
};

struct Derived : Base
{
    Derived(int v) : Base(v) { std::cout << "Derived(" << x << ") constructed\n"; }
    ~Derived() { std::cout << "Derived(" << x << ") destroyed\n"; }
};

struct CustomDeleter
{
    void operator()(Base* b)
    {
        std::cout << "Custom deleter called for Base(" << b->x << ")\n";
        delete b;
    }
};

int main()
{
    using rub::shared_ptr;
    using rub::unique_ptr;

    std::cout << "\n--- Default and nullptr constructor ---\n";
    shared_ptr<Base> sp_default;
    shared_ptr<Base> sp_null(nullptr);
    std::cout << "sp_default.use_count() = " << sp_default.use_count() << "\n";
    std::cout << "sp_null.use_count() = " << sp_null.use_count() << "\n";

    std::cout << "\n--- Raw pointer constructor ---\n";
    shared_ptr<Base> sp1(new Base(1));
    std::cout << "sp1.use_count() = " << sp1.use_count() << "\n";

    std::cout << "\n--- Copy constructor ---\n";
    shared_ptr<Base> sp2(sp1);
    std::cout << "sp1.use_count() = " << sp1.use_count() << "\n";
    std::cout << "sp2.use_count() = " << sp2.use_count() << "\n";

    std::cout << "\n--- Move constructor ---\n";
    shared_ptr<Base> sp3(std::move(sp2));
    std::cout << "sp2.use_count() = " << sp2.use_count() << " (should be 0)\n";
    std::cout << "sp3.use_count() = " << sp3.use_count() << "\n";

    std::cout << "\n--- Copy assignment ---\n";
    shared_ptr<Base> sp4;
    sp4 = sp3;
    std::cout << "sp3.use_count() = " << sp3.use_count() << "\n";
    std::cout << "sp4.use_count() = " << sp4.use_count() << "\n";

    std::cout << "\n--- Move assignment ---\n";
    shared_ptr<Base> sp5;
    sp5 = std::move(sp4);
    std::cout << "sp4.use_count() = " << sp4.use_count() << " (should be 0)\n";
    std::cout << "sp5.use_count() = " << sp5.use_count() << "\n";

    std::cout << "\n--- Reset ---\n";
    sp5.reset();
    std::cout << "sp5.use_count() = " << sp5.use_count() << " (should be 0)\n";

    std::cout << "\n--- Reset with new object ---\n";
    sp5.reset(new Base(2));
    std::cout << "sp5.use_count() = " << sp5.use_count() << "\n";

    std::cout << "\n--- Reset with custom deleter ---\n";
    shared_ptr<Base> sp6;
    sp6.reset(new Base(3), CustomDeleter());
    std::cout << "sp6.use_count() = " << sp6.use_count() << "\n";

    std::cout << "\n--- Swap ---\n";
    std::cout << "Before swap: sp5 = " << sp5.get() << ", sp6 = " << sp6.get() << "\n";
    sp5.swap(sp6);
    std::cout << "After swap: sp5 = " << sp5.get() << ", sp6 = " << sp6.get() << "\n";

    std::cout << "\n--- Unique_ptr conversion ---\n";
    unique_ptr<Base> uptr(new Base(4));
    shared_ptr<Base> sp7;
    sp7 = std::move(uptr);
    std::cout << "uptr.get() = " << uptr.get() << " (should be nullptr)\n";
    std::cout << "sp7.use_count() = " << sp7.use_count() << "\n";

    std::cout << "\n--- Cross-type assignment (Derived -> Base) ---\n";
    shared_ptr<Derived> spd(new Derived(5));
    shared_ptr<Base> spt;
    spt = spd;
    std::cout << "spd.use_count() = " << spd.use_count() << "\n";
    std::cout << "spt.use_count() = " << spt.use_count() << "\n";

    std::cout << "\n--- Cross-type move assignment ---\n";
    shared_ptr<Base> spt2;
    spt2 = std::move(spd);
    std::cout << "spd.use_count() = " << spd.use_count() << " (should be 0)\n";
    std::cout << "spt2.use_count() = " << spt2.use_count() << "\n";

    std::cout << "\n--- get() and get_deleter() ---\n";
    auto dptr = sp5.get();
    std::cout << "sp5.get() = " << dptr << "\n";

    auto deleter_ptr = sp6.get_deleter<CustomDeleter>();
    if (deleter_ptr) std::cout << "sp6 has a custom deleter\n";
    else std::cout << "sp6 has no custom deleter\n";

    std::cout << "\n--- Edge case: reset nullptr ---\n";
    spt.reset(nullptr);
    std::cout << "spt.use_count() = " << spt.use_count() << "\n";
    std::cout << "spt2.use_count() = " << spt2.use_count() << "\n";

    std::cout << "\n--- End of test ---\n";
    return 0;
}
