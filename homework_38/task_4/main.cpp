#include <iostream>
#include "set.h"

int main(void)
{
    std::cout << "=== Empty set ===" << std::endl;
    rub::set<int> empty;
    empty.inorder();   // should print nothing

    std::cout << "\n=== Simple set ===" << std::endl;
    rub::set<int> s{10, 5, 20, 3, 7, 15, 30, 7, 10};

    std::cout << "\nInorder (sorted order):" << std::endl;
    s.inorder();

    std::cout << "\nPreorder:" << std::endl;
    s.preorder();

    std::cout << "\nPostorder:" << std::endl;
    s.postorder();

    std::cout << "\n=== Another set ===" << std::endl;
    rub::set<int> s2{42, 21, 84, 10, 30, 70, 90};

    std::cout << "\nInorder:" << std::endl;
    s2.inorder();

    return 0;
}
