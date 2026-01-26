#include <bits/stdc++.h>
using namespace std;

void explainTuple();

int main()
{
    explainTuple();
    return 0;
}

/*
==================================================
=                 TUPLE (std::tuple)            =
==================================================
= Stores a fixed number of heterogeneous values
= Accessed using std::get<index>(tuple)
= Can nest tuples inside tuples
==================================================
*/

void explainTuple()
{
    /*
    DECLARATION
    ----------------------------------
    tuple<T1, T2, ..., Tn> t;
    */

    tuple<int, string, double> t = {1, "hello", 3.14};
    cout << get<0>(t) << ", "
         << get<1>(t) << ", "
         << get<2>(t) << endl;

    /*
    NESTED TUPLE
    ----------------------------------
    */

    tuple<int, tuple<int, int>, string> nt = {1, {2, 3}, "hi"};
    cout << get<0>(nt) << ", "
         << get<1>(nt).first << ", " // This does NOT work, tuple does not have .first
         << get<2>(nt) << endl;      // You must use get<index>() for all elements

    // Correct way to access a nested tuple:
    cout << get<0>(nt) << ", "
         << get<0>(get<1>(nt)) << ", "
         << get<1>(get<1>(nt)) << ", "
         << get<2>(nt) << endl;

    /*
    MAKE_TUPLE
    ----------------------------------
    make_tuple(x, y, z)
    */

    auto t2 = make_tuple(10, "world", 2.71);
    cout << get<0>(t2) << ", "
         << get<1>(t2) << ", "
         << get<2>(t2) << endl;
}
