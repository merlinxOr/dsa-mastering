#include <bits/stdc++.h>

using namespace std;

/*
 * Divide and Conquer:
 * - Divide the array into halves
 * - Sort each half recursively
 * - Merge the sorted halves
 */

void merge_sort(int *, int, int);
void merge(int *, int, int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {3, 1, 2, 4, 1, 5, 2, 6, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the full array (from index 0 to size - 1)
    merge_sort(arr, 0, size - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
 * merge_sort:
 * - low and high define the current subarray
 * - if low == high, the subarray has one element (already sorted)
 * - split the array into two halves
 * - recursively sort each half
 * - merge the two sorted halves
 */

void merge_sort(int *arr, int low, int high)
{
    // Base case: one element
    if (low == high)
    {
        return;
    }

    // Find the middle point
    int mid = (low + high) / 2;

    // Sort left half
    merge_sort(arr, low, mid);

    // Sort right half
    merge_sort(arr, mid + 1, high);

    // Merge both halves
    merge(arr, low, mid, high);
}

/*
 * merge:
 * - merges two sorted subarrays:
 *   left  -> [low ... mid]
 *   right -> [mid+1 ... high]
 * - uses a temporary array to store sorted elements
 */

void merge(int *arr, int low, int mid, int high)
{
    vector<int> temp;

    // Pointers for left and right subarrays
    int left = low;
    int right = mid + 1;

    // Compare elements from both halves
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // Copy remaining elements from left half
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // Copy remaining elements from right half
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy sorted elements back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
