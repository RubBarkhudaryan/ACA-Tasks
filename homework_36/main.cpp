#include <iostream>
#include "./list.h"

// If you prefer the other way (list.tpp includes list.h),
// you can just do:
// #include "list.tpp"

template <typename T>
void print_list(const rub::List<T> &lst, const char *name)
{
    using ListT = rub::List<T>;
    using Node  = typename ListT::Node;   // requires Node to be accessible

    const Node *cur = lst.front();

    std::cout << name << ": ";
    if (!cur)
    {
        std::cout << "<empty>\n";
        return;
    }

    while (cur)
    {
        std::cout << cur->value;
        if (cur->next)
            std::cout << " -> ";
        cur = cur->next;
    }
    std::cout << '\n';
}

int main()
{
    using rub::List;

    // 1. default ctor: empty list
    List<int> lst;
    print_list(lst, "after default ctor");

    // 2. create some nodes
    auto *n10 = new List<int>::Node(10);
    auto *n20 = new List<int>::Node(20);
    auto *n30 = new List<int>::Node(30);

    // 3. push_front: [20]
    lst.push_front(n20);
    print_list(lst, "after push_front(20)");

    // 4. push_front again: [10 -> 20]
    lst.push_front(n10);
    print_list(lst, "after push_front(10)");

    // 5. insert after 20: [10 -> 20 -> 30]
    lst.insert(n20, n30);
    print_list(lst, "after insert(20, 30)");

	std::cout << "list size: " << lst.size() << "\n";

    // 6. pop_front: [20 -> 30]
    lst.pop_front();
    print_list(lst, "after pop_front #1");

    // 7. pop_front: [30]
    lst.pop_front();
    print_list(lst, "after pop_front #2");

    // 8. pop_front: []
    lst.pop_front();
    print_list(lst, "after pop_front #3");

    // 9. extra pop on empty (should do nothing / no crash)
    lst.pop_front();
    print_list(lst, "after pop_front on empty");

    // IMPORTANT: don't delete n10/n20/n30 manually — the List
    // destructor already deletes all nodes it owns.
    return 0;
}
