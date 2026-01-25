#include <bits/stdc++.h>
using namespace std;

void explainStack();

int main()
{
    explainStack();
    return 0;
}

/*
==================================================
=                 STACK (std::stack)              =
==================================================
= LIFO: Last In, First Out
= Acceso solo al elemento superior
= Todas las operaciones son O(1)
==================================================
*/

void explainStack()
{
    /*
    DECLARATION
    ----------------------------------
    stack<T> st;                // Empty stack
    stack<T> st2(st);           // Copy of stack
    */

    stack<int> st;

    /*
    INSERTION
    ----------------------------------
    push(x)     -> Insert element on top
    emplace(x)  -> Construct element directly on top
    */

    st.push(1);    // {1}
    st.push(2);    // {2, 1}
    st.push(3);    // {3, 2, 1}
    st.push(3);    // {3, 3, 2, 1}
    st.emplace(5); // {5, 3, 3, 2, 1}

    /*
    ELEMENT ACCESS
    ----------------------------------
    top()   -> Access top element
    NOTE: No random access (st[i])
    */

    cout << st.top() << endl; // 5

    /*
    REMOVAL
    ----------------------------------
    pop()   -> Remove top element
    */

    st.pop(); // {3, 3, 2, 1}

    cout << st.top() << endl; // 3

    /*
    UTILITIES
    ----------------------------------
    size()   -> Number of elements
    empty()  -> Check if stack is empty
    swap()   -> Swap contents with another stack
    */

    cout << st.size() << endl;  // 4
    cout << st.empty() << endl; // 0 (false)

    stack<int> st1, st2;
    st1.swap(st2);
}
