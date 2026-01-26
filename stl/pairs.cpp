#include <bits/stdc++.h>
using namespace std;

void explainPair();

int main()
{
    explainPair();
    return 0;
}

/*
==================================================
=                PAIR (std::pair)                 =
==================================================
= Stores two heterogeneous values
= Accessed using .first and .second
==================================================
*/

void explainPair()
{
    /*
    DECLARATION
    ----------------------------------
    pair<T1, T2> p;
    */

    pair<int, int> p = {1, 3};
    cout << p.first << ", " << p.second << endl;

    /*
    NESTED PAIR
    ----------------------------------
    */

    pair<int, pair<int, int>> pp = {1, {3, 4}};
    cout << pp.first << ", "
         << pp.second.first << ", "
         << pp.second.second << endl;

    /*
    ARRAY OF PAIRS
    ----------------------------------
    */

    pair<int, int> arr[] = {{1, 2}, {2, 5}, {5, 1}};
    cout << arr[1].first << endl;

    /*
    MAKE_PAIR
    ----------------------------------
    make_pair(x, y)
    */

    pair<int, int> p2 = make_pair(10, 20);
}
