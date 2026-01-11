/*
// main.cpp
#include "./queue.h"
#include <iostream>
#include <cassert>

template <typename T>
void print_list(const rub::List<T>& lst, const char* title = "")
{
    if (title && *title) std::cout << title << " ";
    std::cout << "[size=" << lst.size() << "]: ";
    using Node = typename rub::List<T>::Node;
    const Node* cur = lst.front();
    while (cur)
    {
        std::cout << cur->value;
        cur = cur->next;
        if (cur) std::cout << " -> ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "==== LIST tests ====" << std::endl;

    // 1) empty list: pop, front/back, size
    {
        rub::List<int> l;
        std::cout << "Empty list created." << std::endl;
        l.pop(); // should be no-op
        assert(l.size() == 0);
        assert(l.front() == nullptr);
        // back() may be present in your implementation
        // if not present, comment the next two lines
        #ifdef HAS_BACK_METHOD
        assert(l.back() == nullptr);
        #endif
        print_list(l, "After empty-pop:");
    }

    // 2) push(nullptr) must be no-op
    {
        rub::List<int> l;
        l.push(nullptr); // no-op
        assert(l.size() == 0);
        print_list(l, "After push(nullptr):");
    }

    // 3) single-element push/pop
    {
        rub::List<int> l;
        using Node = rub::List<int>::Node;
        Node* n1 = new Node(10);
        l.push(n1);
        assert(l.size() == 1);
        assert(l.front() && l.front()->value == 10);
        #ifdef HAS_BACK_METHOD
        assert(l.back() && l.back()->value == 10);
        #endif
        print_list(l, "After pushing one node:");
        l.pop(); // should delete the single node
        assert(l.size() == 0);
        assert(l.front() == nullptr);
        print_list(l, "After popping single element:");
    }

    // 4) multi push, insert after head, insert after tail, pop until empty
    {
        rub::List<int> l;
        using Node = rub::List<int>::Node;

        Node* a = new Node(1);
        Node* b = new Node(2);
        Node* c = new Node(3);

        l.push(a);
        l.push(b);
        l.push(c); // list: 1 -> 2 -> 3
        assert(l.size() == 3);
        print_list(l, "Initial list:");

        // insert after head (after 1) with value 5 -> 1 -> 5 -> 2 -> 3
        Node* insert1 = new Node(5);
        l.insert(l.front(), insert1);
        assert(l.size() == 4);
        print_list(l, "After insert after head (5):");

        // insert after tail (should update tail)
        Node* insertTail = new Node(99);
        l.insert(l.back(), insertTail); // list end becomes 99
        assert(l.size() == 5);
        #ifdef HAS_BACK_METHOD
        assert(l.back() && l.back()->value == 99);
        #endif
        print_list(l, "After insert after tail (99):");

        // insert(nullptr, nullptr) should be no-op (safe)
        l.insert(nullptr, nullptr);
        assert(l.size() == 5);

        // pop back until empty (pop removes tail in List)
        while (l.size() > 0)
        {
            std::cout << "Popping back once..." << std::endl;
            l.pop();
            print_list(l, "List now:");
        }
        assert(l.size() == 0);
        std::cout << "List fully popped." << std::endl;
    }

    std::cout << "\n==== QUEUE tests ====" << std::endl;

    // 5) empty queue pop should be no-op
    {
        rub::Queue<int> q;
        q.pop();
        assert(q.size() == 0);
        print_list(q, "Empty queue:");
    }

    // 6) queue single-element constructor + pop
    {
        rub::Queue<int> q2(42); // construct with single element
        assert(q2.size() == 1);
        print_list(q2, "Queue constructed with 42:");
        q2.pop(); // removes that single head element
        assert(q2.size() == 0);
        print_list(q2, "After popping single-element queue:");
    }

    // 7) queue push/pop order (FIFO)
    {
        rub::Queue<int> q;
        using Node = rub::List<int>::Node;

        Node* a = new Node(10);
        Node* b = new Node(20);
        Node* c = new Node(30);

        q.push(a);
        q.push(b);
        q.push(c); // queue order front-> 10, 20, 30 <- back
        assert(q.size() == 3);
        print_list(q, "Queue after 3 pushes:");

        // pop should remove from head (10), then 20, then 30
        q.pop();
        assert(q.size() == 2);
        print_list(q, "After 1 pop (expect 20 -> 30):");

        q.pop();
        assert(q.size() == 1);
        print_list(q, "After 2 pops (expect 30):");

        q.pop();
        assert(q.size() == 0);
        print_list(q, "After 3 pops (empty):");
    }

    // 8) push(nullptr) on queue should be no-op
    {
        rub::Queue<int> q;
        q.push(nullptr);
        assert(q.size() == 0);
        print_list(q, "Queue after push(nullptr):");
    }

    // 9) destructor tests (scoped objects)
    {
        std::cout << "\nEntering scope to test destructor behavior..." << std::endl;
        {
            rub::List<int> l;
            using Node = rub::List<int>::Node;
            for (int i = 0; i < 5; ++i)
                l.push(new Node(i * 100));
            print_list(l, "Scoped list before leaving scope:");
        } // l destructor runs here
        std::cout << "Scoped list destructor completed without crash." << std::endl;

        {
            rub::Queue<int> q;
            using Node = rub::List<int>::Node;
            for (int i = 0; i < 3; ++i)
                q.push(new Node(1000 + i));
            print_list(q, "Scoped queue before leaving scope:");
        } // q destructor runs here
        std::cout << "Scoped queue destructor completed without crash." << std::endl;
    }

    std::cout << "\nAll tests finished. If assertions passed, behavior matched expectations." << std::endl;
    return 0;
}
*/

#include <iostream>
#include "tree.h"

int main()
{
    rub::Tree<int> root(1);

    root.add_child(2);
    root.add_child(3);
    root.add_child(4);

    rub::Tree<int>* child0 = root.get_child(0);
    rub::Tree<int>* child2 = root.get_child(2);

    if (child0)
    {
        child0->add_child(5);
        child0->add_child(6);
    }

    if (child2)
        child2->add_child(7);

    std::cout << "BFS traversal:" << std::endl;
    root.print();

    return 0;
}
