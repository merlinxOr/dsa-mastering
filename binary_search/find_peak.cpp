#include <bits/stdc++.h>
using namespace std;

int findPeak_bf(vector<int> &arr);
int findPeak(vector<int> &arr);

int main()
{
    vector<int> arr = {1, 3, 20, 4, 1, 0};

    int peakIndex_bf = findPeak_bf(arr);
    int peakIndex_bs = findPeak(arr);

    cout << "Peak index (BF): " << peakIndex_bf << ", value: " << arr[peakIndex_bf] << endl;
    cout << "Peak index (BS): " << peakIndex_bs << ", value: " << arr[peakIndex_bs] << endl;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int findPeak_bf(vector<int> &arr)
{
    int n = arr.size();
    if (n == 1)
        return 0;

    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || arr[i] >= arr[i - 1]) &&
            (i == n - 1 || arr[i] >= arr[i + 1]))
            return i;
    }

    return -1;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int findPeak(vector<int> &arr)
{
    int left = 0, right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}