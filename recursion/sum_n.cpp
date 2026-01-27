#include <bits/stdc++.h>

using namespace std;

void sum_n_parameterised(int, int);
int sum_n_functional(int);

int main(int argc, char const *argv[])
{
    sum_n_parameterised(3, 0);
    cout << sum_n_functional(3) << endl;
    return 0;
}

void sum_n_parameterised(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }

    sum_n_parameterised(i - 1, sum + i);
}

int sum_n_functional(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum_n_functional(n - 1);
}
