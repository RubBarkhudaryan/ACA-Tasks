#include <iostream>
#include "./stack.h"

int main()
{
    // Create a stack of integers
    rub::Stack<int> s;

    std::cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;

    // Push some elements
    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "After pushing 10, 20, 30:" << std::endl;
    std::cout << "Top element: " << s.top() << std::endl; // should be 30
    std::cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;

    // Pop one element
    s.pop();
    std::cout << "After one pop, top element: " << s.top() << std::endl; // should be 20

    // Push another element
    s.push(40);
    std::cout << "After pushing 40, top element: " << s.top() << std::endl; // should be 40

    // Pop all elements
    std::cout << "Popping all elements:" << std::endl;
    while (!s.empty())
    {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl;

    std::cout << "Stack empty? " << (s.empty() ? "Yes" : "No") << std::endl;

    return 0;
}
