#include <bits/stdc++.h>
using namespace std;

int kth_missing_bf(vector<int> &arr, int k);
int kth_missing_optimal(vector<int> &arr, int k);

int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int res = kth_missing_optimal(arr, k);

    cout << res << endl;
}

/*
 * Time complexity = O(n + k)
 * Space complexity = O(1)
 */
int kth_missing_bf(vector<int> &arr, int k)
{
    int n = arr.size();
    int missing = 0;
    int current = 1;
    int i = 0;

    while (true)
    {
        if (i < n && arr[i] == current)
        {
            i++;
        }
        else
        {
            missing++;
            if (missing == k)
                return current;
        }
        current++;
    }
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int kth_missing_optimal(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // number of missing elements before index mid
        int missing = arr[mid] - (mid + 1);

        if (missing < k)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // final answer
    return low + k;
}