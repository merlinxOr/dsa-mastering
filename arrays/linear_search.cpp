#include <bits/stdc++.h>

using namespace std;

int linear_search(int *, int, int);

int main(int argc, char const *argv[])
{

    int arr[] = {6, 7, 8, 4, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << linear_search(arr, size, 4) << endl;

    return 0;
}

int linear_search(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }

    return -1;
}
