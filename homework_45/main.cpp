#include <iostream>
#include "./unique.hpp"

struct Base {
    virtual ~Base() { std::cout << "Base destroyed\n"; }
    virtual void hello() { std::cout << "Base hello\n"; }
};

struct Derived : Base {
    ~Derived() { std::cout << "Derived destroyed\n"; }
    void hello() override { std::cout << "Derived hello\n"; }
};

struct CustomDeleter {
    void operator()(Base* ptr) {
        std::cout << "Custom deleting...\n";
        delete ptr;
    }
};

int main()
{
    std::cout << "---- Basic construction ----\n";
    rub::unique_ptr<int> p1(new int(42));
    std::cout << *p1 << "\n";

    std::cout << "\n---- Move constructor ----\n";
    rub::unique_ptr<int> p2(std::move(p1));
    if (!p1.get())
        std::cout << "p1 is null after move\n";
    std::cout << *p2 << "\n";

    std::cout << "\n---- Move assignment ----\n";
    rub::unique_ptr<int> p3;
    p3 = std::move(p2);
    if (!p2.get())
        std::cout << "p2 is null after move assignment\n";
    std::cout << *p3 << "\n";

    std::cout << "\n---- nullptr assignment ----\n";
    p3 = nullptr;
    if (!p3.get())
        std::cout << "p3 is null after nullptr assignment\n";

    std::cout << "\n---- reset() test ----\n";
    p3.reset(new int(99));
    std::cout << *p3 << "\n";

    std::cout << "\n---- release() test ----\n";
    int* raw = p3.release();
    if (!p3.get())
        std::cout << "p3 released ownership\n";
    std::cout << *raw << "\n";
    delete raw;

    std::cout << "\n---- Polymorphic move constructor ----\n";
    rub::unique_ptr<Derived> d(new Derived());
    rub::unique_ptr<Base> b(std::move(d));
    b->hello();

    std::cout << "\n---- Polymorphic move assignment ----\n";
    rub::unique_ptr<Derived> d2(new Derived());
    rub::unique_ptr<Base> b2;
    b2 = std::move(d2);
    b2->hello();

    std::cout << "\n---- Custom deleter ----\n";
    rub::unique_ptr<Base, CustomDeleter> custom(new Derived(), CustomDeleter{});
    custom->hello();

    std::cout << "\n---- End of main ----\n";
    return 0;
}
