#include <bits/stdc++.h>
using namespace std;

void explainList();
void explainForwardList();

int main()
{
    explainList();
    explainForwardList();
    return 0;
}

/*
==================================================
=                 LIST (std::list)                =
==================================================
*/

void explainList()
{
    /*
    std::list
    ----------------------------------
    Doubly linked list
    No random access (no operator[])
    Fast insertions and deletions
    */

    list<int> ls;

    /*
    INSERTION
    ----------------------------------
    */

    ls.push_back(2);
    ls.emplace_back(4);
    ls.push_front(1);
    ls.emplace_front(0);

    /*
    ITERATION
    ----------------------------------
    */

    for (int x : ls)
        cout << x << " ";
    cout << endl;

    /*
    IMPORTANT FUNCTIONS
    ----------------------------------
    begin(), end(), rbegin(), rend()
    insert(), erase(), clear()
    size(), empty(), swap()
    remove(value) -> Remove all elements equal to value
    */

    ls.remove(2);
}

/*
==================================================
=          FORWARD LIST (std::forward_list)       =
==================================================
*/

void explainForwardList()
{
    /*
    std::forward_list
    ----------------------------------
    Singly linked list
    Only forward traversal
    Lower memory usage than list
    No size() function
    */

    forward_list<int> fl;

    /*
    INSERTION
    ----------------------------------
    */

    fl.push_front(3);    // {3}
    fl.emplace_front(2); // {2, 3}
    fl.push_front(1);    // {1, 2, 3}

    /*
    ITERATION
    ----------------------------------
    */

    for (int x : fl)
        cout << x << " ";
    cout << endl;

    /*
    IMPORTANT FUNCTIONS
    ----------------------------------
    begin(), end(), before_begin()
    insert_after(), erase_after()
    clear(), empty(), swap()
    remove(value) -> Remove all elements equal to value
    */

    fl.remove(2);
}
