#include <bits/stdc++.h>
using namespace std;

void explainQueue();

int main()
{
    explainQueue();
    return 0;
}

/*
==================================================
=                QUEUE (std::queue)               =
==================================================
= FIFO: First In, First Out
= Access only to front and back
= All operations are O(1)
==================================================
*/

void explainQueue()
{
    /*
    DECLARATION
    ----------------------------------
    queue<T> q;              // Empty queue
    */

    queue<int> q;

    /*
    INSERTION
    ----------------------------------
    push(x)     -> Insert element at the back
    emplace(x)  -> Construct element at the back
    */

    q.push(1);    // {1}
    q.push(2);    // {1, 2}
    q.emplace(4); // {1, 2, 4}

    /*
    ELEMENT ACCESS
    ----------------------------------
    front() -> Access first element
    back()  -> Access last element
    */

    q.back() += 5;            // {1, 2, 9}
    cout << q.back() << endl; // 9

    cout << q.front() << endl; // 1

    /*
    REMOVAL
    ----------------------------------
    pop() -> Removes front element
    */

    q.pop(); // {2, 9}

    cout << q.front() << endl; // 2

    /*
    UTILITIES
    ----------------------------------
    size()   -> Number of elements
    empty()  -> Check if queue is empty
    swap()   -> Swap contents with another queue
    */

    cout << q.size() << endl;
    cout << q.empty() << endl;
}
