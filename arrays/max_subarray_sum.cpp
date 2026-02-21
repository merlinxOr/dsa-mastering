#include <bits/stdc++.h>
using namespace std;

int max_subarray_sum_bf(int *, int);
int max_subarray_sum_better(int *, int);
int max_subarray_sum_optimal(int *, int);

int main(int argc, char const *argv[])
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Brute Force: " << max_subarray_sum_bf(arr, size) << endl;
    cout << "Better: " << max_subarray_sum_better(arr, size) << endl;
    cout << "Optimal (Kadane): " << max_subarray_sum_optimal(arr, size) << endl;

    return 0;
}

/*
 * Time complexity = O(n³)
 * Space complexity = O(1)
 */
int max_subarray_sum_bf(int *arr, int size)
{
    int max_sum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
int max_subarray_sum_better(int *arr, int size)
{
    int max_sum = INT_MIN;

    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += arr[j];
            max_sum = max(max_sum, sum);
        }
    }

    return max_sum;
}

/*
 * Kadane's Algorithm
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int max_subarray_sum_optimal(int *arr, int size)
{
    long long sum = 0;
    long long max_sum = LLONG_MIN;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        max_sum = max(max_sum, sum);

        if (sum < 0)
        {
            sum = 0;
        }
    }

    return max_sum;
}