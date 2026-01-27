#include <bits/stdc++.h>

using namespace std;

int fibonacci(int);

int main(int argc, char const *argv[])
{
    cout << fibonacci(4) << endl;
    return 0;
}

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}