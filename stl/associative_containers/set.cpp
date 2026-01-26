#include <bits/stdc++.h>
using namespace std;

void explainSet();
void explainMultiset();
void explainUnorderedSet();

int main()
{
    explainSet();
    explainMultiset();
    explainUnorderedSet();
    return 0;
}

/*
==================================================
=                 SET (std::set)                  =
==================================================
= Stores unique elements
= Automatically ordered
= Implemented as a balanced tree
= Operations take O(log n)
==================================================
*/

void explainSet()
{
    /*
    DECLARATION
    ----------------------------------
    set<T> st;               // Empty set
    set<T> st2(st);          // Copy of set
    */

    set<int> st;

    /*
    INSERTION
    ----------------------------------
    insert(x)   -> Insert element
    emplace(x)  -> Construct element in place
    */

    st.insert(1);  // {1}
    st.emplace(2); // {1, 2}
    st.insert(2);  // {1, 2}
    st.insert(4);  // {1, 2, 4}
    st.insert(3);  // {1, 2, 3, 4}

    /*
    ITERATORS
    ----------------------------------
    begin(), end(), rbegin(), rend()
    */

    for (int x : st)
        cout << x << " ";
    cout << endl;

    /*
    SEARCH
    ----------------------------------
    find(x)   -> Returns iterator to x or end()
    count(x)  -> Returns 0 or 1
    */

    auto it = st.find(3);  // Found
    auto it2 = st.find(6); // st.end()

    int cnt = st.count(1); // 0 or 1

    /*
    ERASE
    ----------------------------------
    erase(x)        -> Erase by value (O(log n))
    erase(it)       -> Erase by iterator (O(1))
    erase(it1,it2)  -> Erase range [it1, it2)
    */

    st.erase(4); // {1, 2, 3}

    auto it3 = st.find(2);
    if (it3 != st.end())
        st.erase(it3); // {1, 3}

    /*
    RANGE ERASE
    ----------------------------------
    */

    st.insert(2);
    st.insert(4);
    st.insert(5); // {1, 2, 3, 4, 5}

    auto it4 = st.find(2);
    auto it5 = st.find(4);
    st.erase(it4, it5); // {1, 4, 5}

    /*
    BOUNDS
    ----------------------------------
    lower_bound(x) -> First element >= x
    upper_bound(x) -> First element > x
    */

    auto lb = st.lower_bound(2);
    auto ub = st.upper_bound(4);
}

/*
==================================================
=              MULTISET (std::multiset)           =
==================================================
= Allows duplicate elements
= Ordered
= Operations take O(log n)
==================================================
*/

void explainMultiset()
{
    multiset<int> ms;

    /*
    INSERTION
    ----------------------------------
    */

    ms.insert(1); // {1}
    ms.insert(1); // {1, 1}
    ms.insert(1); // {1, 1, 1}

    /*
    COUNT
    ----------------------------------
    */

    int cnt = ms.count(1); // 3

    /*
    ERASE
    ----------------------------------
    erase(x)        -> Erases all occurrences of x
    erase(it)       -> Erases one element
    erase(it1,it2)  -> Erases range
    */

    ms.erase(1); // {}

    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // {1, 1, 1}

    auto it = ms.find(1);
    ms.erase(it); // {1, 1}

    auto it1 = ms.begin();
    auto it2 = next(ms.begin(), 2);
    ms.erase(it1, it2); // {}
}

/*
==================================================
=          UNORDERED SET (std::unordered_set)     =
==================================================
= Stores unique elements
= Not ordered
= Hash table based
= Average complexity O(1)
= Worst case O(n) due to collisions
==================================================
*/

void explainUnorderedSet()
{
    unordered_set<int> ust;

    /*
    INSERTION
    ----------------------------------
    */

    ust.insert(1);
    ust.insert(2);
    ust.insert(3);

    /*
    SEARCH
    ----------------------------------
    */

    auto it = ust.find(2); // Average O(1)

    /*
    NOTES
    ----------------------------------
    - Does not maintain order
    - No lower_bound / upper_bound
    - Faster than set in most cases
    */
}
