#include <bits/stdc++.h>

using namespace std;

/*
 * Select the min and swap
 */

void selection_sort(int *, int);

int main(int argc, char const *argv[])
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    selection_sort(arr, size);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
