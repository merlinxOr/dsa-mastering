#include <bits/stdc++.h>

using namespace std;

int factorial(int);

int main(int argc, char const *argv[])
{
    cout << factorial(3) << endl;
    return 0;
}

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}