#include <bits/stdc++.h>

using namespace std;

void explainList();

int main(int argc, char const *argv[])
{
    explainList();
    return 0;
}

/*
==================================================
=                 LIST (std::list)               =
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
    remove(value)     -> Remove all elements equal to value
    */

    ls.remove(2);
}