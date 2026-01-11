#include <iostream>
#include "./queue.h"

int main()
{
    // Create an empty queue of integers
    rub::Queue<int> q;

    // Push some elements
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "After pushing 10, 20, 30:" << std::endl;

    // Print top element
    std::cout << "Top element: " << q.top() << std::endl; // should be 10

    // Pop one element
    q.pop();
    std::cout << "After one pop, top element: " << q.top() << std::endl; // should be 20

    // Push more elements
    q.push(40);
    q.push(50);
    std::cout << "After pushing 40, 50, top element: " << q.top() << std::endl; // should still be 20

    // Pop all elements and print
    std::cout << "Popping all elements:" << std::endl;
    while (!q.empty())
    {
        try
        {
            std::cout << q.top() << " ";
            q.pop();
        }
        catch (...)
        {
            break;
        }

        if (q.top() == 0 && false) // just to suppress compiler warnings
            break;
    }
    std::cout << std::endl;

    return 0;
}
