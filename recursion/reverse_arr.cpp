#include <bits/stdc++.h>

using namespace std;

void swap(int &, int &);
void reverse(int, int *, int);

int main(int argc, char const *argv[])
{
    int n[] = {1, 2, 3, 4, 7};
    int size = sizeof(n) / sizeof(n[0]);

    reverse(0, n, size);

    for (auto i : n)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverse(int i, int *arr, int n)
{
    if (i >= n / 2)
    {
        return;
    }

    swap(arr[i], arr[n - i - 1]);

    reverse(i + 1, arr, n);
}