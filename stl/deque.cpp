#include <bits/stdc++.h>
using namespace std;

void explainDeque();

int main()
{
    explainDeque();
    return 0;
}

/*
==================================================
=                  DEQUE (std::deque)             =
==================================================
= Double-ended queue
= Can insert and remove elements from both ends
= Random access supported
= All operations at ends are O(1)
==================================================
*/

void explainDeque()
{
    /*
    DECLARATION
    ----------------------------------
    deque<T> dq;               // Empty deque
    */

    deque<int> dq;

    /*
    INSERTION
    ----------------------------------
    push_back(x)      -> Insert at back
    emplace_back(x)   -> Construct at back
    push_front(x)     -> Insert at front
    emplace_front(x)  -> Construct at front
    */

    dq.push_back(1);     // {1}
    dq.emplace_back(2);  // {1, 2}
    dq.push_front(3);    // {3, 1, 2}
    dq.emplace_front(4); // {4, 3, 1, 2}

    /*
    REMOVAL
    ----------------------------------
    pop_back()  -> Remove from back
    pop_front() -> Remove from front
    */

    dq.pop_back();  // {4, 3, 1}
    dq.pop_front(); // {3, 1}

    /*
    ELEMENT ACCESS
    ----------------------------------
    front() -> Access first element
    back()  -> Access last element
    operator[] and at() are also supported
    */

    cout << dq.front() << endl; // 3
    cout << dq.back() << endl;  // 1

    /*
    IMPORTANT FUNCTIONS
    ----------------------------------
    begin(), end(), rbegin(), rend() -> Iterators
    insert(pos, value)               -> Insert at position
    erase(pos) / erase(begin, end)   -> Remove elements
    clear()                          -> Remove all elements
    size(), empty(), swap()           -> Utility functions
    remove(value)                    -> Remove all elements equal to value (use remove-erase idiom)
    */
}
