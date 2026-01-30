#include <bits/stdc++.h>

using namespace std;

/*
 * Take an element and place it in correct order
 */

void insertion_sort(int *, int);

int main(int argc, char const *argv[])
{
    int arr[] = {13, 46, 24, 52, 20, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertion_sort(arr, size);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
 * The while loop moves the current element into its correct position:
 * - while (j > 0 && arr[j - 1] > arr[j])
 * - - j starts at i, the element to insert
 * - - it moves backwards through the sorted portion of the array
 * - - if arr[j - 1] > arr[j], we swap them to shift the larger element right
 * - - j decreases each time, until we reach the beginning or find an element <= arr[j]
 *
 * Example with arr = [5, 2, 4], i = 1:
 * - j = 1 → compare 5 > 2 → swap → array becomes [2, 5, 4]
 * - j = 0 → stop, element 2 is in correct place
 *
 * Each iteration of while “grows” the sorted portion by moving the current element left
 * and shifting larger elements right.
 */
void insertion_sort(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;

            j--;
        }
    }
}
