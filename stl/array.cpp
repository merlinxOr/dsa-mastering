#include <bits/stdc++.h>
using namespace std;

void explainArray();

int main()
{
    explainArray();
    return 0;
}

/*
==================================================
=                 ARRAY (std::array)            =
==================================================
= Fixed-size array, behaves like a lightweight container
= Supports random access, iteration, and size()
==================================================
*/

void explainArray()
{
    /*
    DECLARATION
    ----------------------------------
    array<T, N> arr;
    */

    array<int, 5> arr = {1, 2, 3, 4, 5};

    // Access elements by index
    cout << arr[0] << ", " << arr[4] << endl;

    // Size of the array
    cout << "Size: " << arr.size() << endl;

    // Iterating using range-based for
    cout << "Elements: ";
    for (auto x : arr)
        cout << x << " ";
    cout << endl;

    // Iterating using iterators
    cout << "Using iterators: ";
    for (auto it = arr.begin(); it != arr.end(); ++it)
        cout << *it << " ";
    cout << endl;

    /*
    ARRAY OF ARRAYS (2D array)
    ----------------------------------
    */

    array<array<int, 3>, 2> arr2d = {{{1, 2, 3}, {4, 5, 6}}};
    cout << arr2d[1][2] << endl; // prints 6
}
