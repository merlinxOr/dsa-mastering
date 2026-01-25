#include <bits/stdc++.h> // Include all libraries (competitive programming)
using namespace std;

void explainVector();

int main()
{
    explainVector();
    return 0;
}

/*
==================================================
=                 VECTOR (std::vector)           =
==================================================
*/

void explainVector()
{
    /*
    DECLARATION
    ----------------------------------
    vector<T> v;                    // Empty vector
    vector<T> v(n);                 // n default-initialized elements
    vector<T> v(n, value);          // n elements initialized with value
    vector<T> v2(v1);               // Copy of v1
    */

    vector<int> v1;
    vector<int> v2(5);
    vector<int> v3(5, 100);
    vector<int> v4(v3);

    /*
    INSERTION
    ----------------------------------
    push_back(x)    -> Insert element at the end (may create copies)
    emplace_back()  -> Construct element directly inside the vector
    */

    v1.push_back(1);
    v1.emplace_back(2);

    vector<pair<int, int>> vp;
    vp.push_back({1, 2});  // Object created before insertion
    vp.emplace_back(3, 4); // Object created inside the vector

    /*
    ELEMENT ACCESS
    ----------------------------------
    v[i]        -> No bounds checking
    v.at(i)     -> Bounds checking (throws exception)
    v.front()   -> First element
    v.back()    -> Last element
    */

    cout << v3[0] << endl;
    cout << v3.at(0) << endl;
    cout << v3.back() << endl;

    /*
    ITERATORS
    ----------------------------------
    begin()   -> First element
    end()     -> One past the last element
    rbegin()  -> Reverse begin (last element)
    rend()    -> Reverse end (before first element)
    */

    vector<int> v = {10, 20, 30, 40};

    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl;

    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";

    cout << endl;

    for (int x : v)
        cout << x << " ";

    cout << endl;

    /*
    ERASE
    ----------------------------------
    erase(pos)            -> Remove element at position
    erase(begin, end)     -> Remove range [begin, end)
    pop_back()            -> Remove last element
    */

    v.erase(v.begin() + 1);            // Remove 20
    v.erase(v.begin(), v.begin() + 2); // Remove first two elements

    /*
    INSERT
    ----------------------------------
    insert(pos, value)
    insert(pos, count, value)
    insert(pos, begin, end)
    */

    vector<int> a = {100, 100};
    a.insert(a.begin(), 50);
    a.insert(a.begin() + 1, 2, 10);

    vector<int> b = {1, 2};
    a.insert(a.begin(), b.begin(), b.end());

    /*
    UTILITIES
    ----------------------------------
    size()      -> Number of elements
    empty()     -> Check if vector is empty
    clear()     -> Remove all elements
    swap(v2)    -> Swap contents
    */

    cout << a.size() << endl;
    a.clear();
    cout << a.empty() << endl;
}
