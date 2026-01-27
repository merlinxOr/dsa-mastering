#include <bits/stdc++.h>

using namespace std;

void print_range_n(int, int);
void print_range_n_reverse(int, int);
void print_range_n_backtracking(int, int);
void print_range_n_reverse_backtracking(int, int);

int main(int argc, char const *argv[])
{
    print_range_n(1, 30);
    print_range_n_reverse(1, 30);
    print_range_n_backtracking(1, 30);
    print_range_n_reverse_backtracking(1, 30);
    return 0;
}

void print_range_n(int i, int n)
{
    if (i > n)
    {
        cout << endl;
        return;
    }

    cout << i << " ";

    print_range_n(i + 1, n);
}

void print_range_n_reverse(int i, int n)
{
    if (i > n)
    {
        cout << endl;
        return;
    }

    cout << n << " ";

    print_range_n_reverse(i, n - 1);
}

void print_range_n_backtracking(int i, int n)
{
    if (i > n)
    {
        cout << endl;
        return;
    }

    print_range_n_backtracking(i, n - 1);

    cout << n << " ";
}

void print_range_n_reverse_backtracking(int i, int n)
{
    if (i > n)
    {
        cout << endl;
        return;
    }

    print_range_n_reverse_backtracking(i + 1, n);

    cout << i << " ";
}
