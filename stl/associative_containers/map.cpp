#include <bits/stdc++.h>
using namespace std;

void explainMap();
void explainMultimap();
void explainUnorderedMap();

int main()
{
    explainMap();
    explainMultimap();
    explainUnorderedMap();
    return 0;
}

/*
==================================================
=                  MAP (std::map)                 =
==================================================
= Stores key-value pairs
= Keys are unique
= Automatically ordered by key
= Implemented as a balanced tree
= Operations take O(log n)
==================================================
*/

void explainMap()
{
    /*
    DECLARATION
    ----------------------------------
    map<Key, Value> mpp;
    */

    map<int, int> mpp;
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp3;

    /*
    INSERTION
    ----------------------------------
    */

    mpp[1] = 2;         // {1 -> 2}
    mpp.emplace(3, 1);  // {3 -> 1}
    mpp.insert({2, 4}); // {2 -> 4}
    mpp3[{12, 3}] = 10; // {{12,3} -> 10}

    /*
    INTERNAL ORDER (by key)
    ----------------------------------
    {1 -> 2}
    {2 -> 4}
    {3 -> 1}
    */

    /*
    ITERATION
    ----------------------------------
    */

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    /*
    ACCESS
    ----------------------------------
    operator[] creates key if not present
    */

    cout << mpp[1] << endl; // 2
    cout << mpp[5] << endl; // 0 (key created)

    /*
    SEARCH
    ----------------------------------
    */

    auto it = mpp.find(3);
    if (it != mpp.end())
        cout << it->second << endl;

    auto it2 = mpp.find(5); // mpp.end() if not found

    /*
    BOUNDS
    ----------------------------------
    */

    auto lb = mpp.lower_bound(2); // first key >= 2
    auto ub = mpp.upper_bound(3); // first key > 3

    /*
    UTILITIES
    ----------------------------------
    erase(), swap(), size(), empty()
    */
}

/*
==================================================
=              MULTIMAP (std::multimap)           =
==================================================
= Allows duplicate keys
= Ordered by key
= Operations take O(log n)
==================================================
*/

void explainMultimap()
{
    multimap<int, int> mpp;

    /*
    INSERTION
    ----------------------------------
    */

    mpp.insert({1, 10});
    mpp.insert({1, 20});
    mpp.insert({2, 30});

    /*
    NOTES
    ----------------------------------
    - Duplicate keys allowed
    - operator[] cannot be used
    - find() returns iterator to first occurrence
    */
}

/*
==================================================
=          UNORDERED MAP (std::unordered_map)     =
==================================================
= Stores key-value pairs
= Keys are unique
= Not ordered
= Hash table based
= Average complexity O(1)
= Worst case O(n) due to collisions
==================================================
*/

void explainUnorderedMap()
{
    unordered_map<int, int> umpp;

    umpp[1] = 100;
    umpp[2] = 200;

    /*
    NOTES
    ----------------------------------
    - No ordering
    - No lower_bound / upper_bound
    - Faster than map in most cases
    */
}

/*
==================================================
=              CUSTOM COMPARATOR                  =
==================================================
= Used for sorting pairs
==================================================
*/

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second == p2.second)
        return p1.first > p2.first;
    return false;
}
