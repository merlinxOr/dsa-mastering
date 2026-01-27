#include <bits/stdc++.h>

using namespace std;

void print_name(int, int);

int main(int argc, char const *argv[])
{
    print_name(1, 3);
    return 0;
}

void print_name(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << "Hello recursion!" << endl;

    print_name(i + 1, n);
}
