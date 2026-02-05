#include <bits/stdc++.h>

using namespace std;

void left_rotate(int *, int, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    left_rotate(arr, size, 2);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void left_rotate(int *arr, int n, int d)
{
    if (n == 0)
    {
        return;
    }

    d = d % n;
    if (d == 0)
    {
        return;
    }

    int *temp = new int[d];

    for (int i = 0; i < d; i++)
    {
        temp[i] = arr[i];
    }

    for (int i = d; i < n; i++)
    {
        arr[i - d] = arr[i];
    }

    int j = 0;
    for (int i = n - d; i < n; i++, j++)
    {

        arr[i] = temp[j];
    }
}
