#include <bits/stdc++.h>
using namespace std;

/*
 * Recursive Bubble Sort:
 * - Push the largest element to the end by adjacent swaps
 * - Recurse on the remaining unsorted part
 */

void bubble_sort(int *, int, int);

int main()
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n, 0); // sort the full array

    for (auto x : arr)
        cout << x << " ";
    cout << endl;
}

/*
 * Parameters:
 * - arr: array to sort
 * - n: size of the current unsorted part
 * - i: current index in this pass
 */
void bubble_sort(int *arr, int n, int i)
{
    if (n <= 1)
        return; // base case: one element left

    if (i < n - 1)
    {
        // swap adjacent elements if out of order
        if (arr[i + 1] < arr[i])
            swap(arr[i + 1], arr[i]);

        bubble_sort(arr, n, i + 1); // continue this pass
    }
    else
    {
        bubble_sort(arr, n - 1, 0); // start next pass on smaller part
    }
}
