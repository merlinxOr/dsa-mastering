#include <bits/stdc++.h>

using namespace std;

/*
 * Take an element and place it in correct order
 */

void insertion_sort(int *, int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, size, 0);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

void insertion_sort(int *arr, int n, int i)
{
    if (i >= n)
        return;

    int j = i;

    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j];
        arr[j] = arr[j - 1];
        arr[j - 1] = temp;
        j--;
    }

    insertion_sort(arr, n, i + 1);
}
