#include <bits/stdc++.h>

using namespace std;

bool is_sorted(int *, int);

int main(int argc, char const *argv[])
{

    int arr1[] = {1, 2, 2, 3, 3, 4};
    int size = sizeof(arr1) / sizeof(arr1[0]);

    cout << (is_sorted(arr1, size) ? "Is sorted" : "Is not sorted") << endl;

    int arr2[] = {1, 2, 1, 3, 4};
    size = sizeof(arr2) / sizeof(arr2[0]);
    cout << (is_sorted(arr2, size) ? "Is sorted" : "Is not sorted") << endl;

    return 0;
}

bool is_sorted(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }

    return true;
}
