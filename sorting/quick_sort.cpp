#include <bits/stdc++.h>
using namespace std;

/*
 * Quick Sort (Divide and Conquer):
 * - Select a pivot element
 * - Partition the array so that elements <= pivot are on the left, > pivot on the right
 * - Recursively sort left and right subarrays
 */

vector<int> quick_sort(vector<int> &arr);
void qs(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);

int main()
{
    vector<int> arr = {13, 46, 24, 52, 20, 9};

    // Sort the full array (from index 0 to size-1)
    vector<int> result = quick_sort(arr);

    // Print the sorted array
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
 * quick_sort:
 * - Wrapper function for qs
 * - Returns a sorted copy of the original array
 */
vector<int> quick_sort(vector<int> &arr)
{
    qs(arr, 0, arr.size() - 1); // Sort full array
    return arr;
}

/*
 * qs (recursive quicksort):
 * - Sorts the subarray arr[low ... high]
 * - Base case: if low >= high, the subarray has 0 or 1 element
 * - Otherwise:
 *   1. Partition the array around a pivot
 *   2. Recursively sort left subarray
 *   3. Recursively sort right subarray
 */
void qs(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high); // Partition and get pivot index
        qs(arr, low, pIndex - 1);               // Sort left side
        qs(arr, pIndex + 1, high);              // Sort right side
    }
}

/*
 * partition:
 * - Chooses the first element as pivot
 * - Rearranges elements so that:
 *   - elements <= pivot are on the left
 *   - elements > pivot are on the right
 * - Returns the final index of the pivot
 */
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low]; // Choose first element as pivot
    int i = low + 1;      // Start scanning from the element after pivot
    int j = high;         // Start scanning from the end

    while (true)
    {
        // Move i right while elements are <= pivot
        while (i <= high && arr[i] <= pivot)
            i++;

        // Move j left while elements are > pivot
        while (arr[j] > pivot)
            j--;

        // If pointers cross, partitioning is done
        if (i < j)
            swap(arr[i], arr[j]); // Swap elements on wrong side
        else
            break;
    }

    swap(arr[low], arr[j]); // Place pivot in correct position
    return j;               // Return pivot index
}
