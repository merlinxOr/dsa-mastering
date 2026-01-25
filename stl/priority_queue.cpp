#include <bits/stdc++.h>
using namespace std;

void explainPQ();

int main()
{
    explainPQ();
    return 0;
}

/*
==================================================
=           PRIORITY QUEUE (std::priority_queue)  =
==================================================
= By default: Max-Heap (largest element on top)
= push()  -> O(log n)
= top()   -> O(1)
= pop()   -> O(log n)
==================================================
*/

void explainPQ()
{
    /*
    MAX HEAP
    ----------------------------------
    */

    priority_queue<int> pq;

    /*
    INSERTION
    ----------------------------------
    push(x)     -> Insert element
    emplace(x)  -> Construct element in place
    */

    pq.push(5);     // {5}
    pq.push(2);     // {5, 2}
    pq.push(8);     // {8, 5, 2}
    pq.emplace(10); // {10, 8, 5, 2}

    /*
    ELEMENT ACCESS
    ----------------------------------
    top() -> Access maximum element
    */

    cout << pq.top() << endl; // 10

    /*
    REMOVAL
    ----------------------------------
    pop() -> Remove top element
    */

    pq.pop(); // {8, 5, 2}

    cout << pq.top() << endl; // 8

    /*
    UTILITIES
    ----------------------------------
    size(), empty(), swap()
    */

    /*
    MIN HEAP
    ----------------------------------
    priority_queue<T, vector<T>, greater<T>>
    */

    priority_queue<int, vector<int>, greater<int>> minPQ;

    minPQ.push(5);     // {5}
    minPQ.push(2);     // {2, 5}
    minPQ.push(8);     // {2, 5, 8}
    minPQ.emplace(10); // {2, 5, 8, 10}

    cout << minPQ.top() << endl; // 2
}
