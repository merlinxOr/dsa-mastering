#include <bits/stdc++.h>

using namespace std;

/*
 * Push the max to the last by adjacent swap
 */

void bubble_sort(int *, int);

int main(int argc, char const *argv[])
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
 * The first for defines the boundary of the unsorted part:
 * - for (int i = n - 1; i >= 1; i--)
 * - if n = 6, i starts at 5, then goes to 4, 3, ...
 * - on each iteration, the boundary is reduced
 * - the last elements are already in their correct position
 *
 * The second version counts the number of passes:
 * - for (int i = 0; i < n - 1; i++)
 * - after each pass, one more element at the end is in place
 * - i < n - 1 avoids accessing out of bounds
 */

void bubble_sort(int *arr, int n)
{
    for (int i = n - 1; i >= 1; i--) // for (int i = 0; i < n - 1; i++) {
    {
        for (int j = 0; j <= i - 1; j++) // for (int j = 0; j < n - i - 1; j++) {
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
