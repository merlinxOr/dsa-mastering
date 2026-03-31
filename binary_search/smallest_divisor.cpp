#include <bits/stdc++.h>
using namespace std;

int smallest_divisor_bf(vector<int> &arr, int k);
int smallest_divisor_optimal(vector<int> &arr, int k);

long long calc_sum(vector<int> &arr, int divisor);

int main()
{
    vector<int> arr = {1, 2, 5, 9};
    int k = 6;

    int res = smallest_divisor_optimal(arr, k);

    cout << res << endl;
}

/*
 * Time complexity = O(n * max(arr))
 * Space complexity = O(1)
 */
int smallest_divisor_bf(vector<int> &arr, int k)
{
    int maxEle = *max_element(arr.begin(), arr.end());
    int ans = maxEle;

    for (int d = 1; d <= maxEle; d++)
    {
        long long total = 0;
        for (int x : arr)
            total += (x + d - 1) / d;

        if (total <= k)
        {
            ans = d;
            break;
        }
    }

    return ans;
}

/*
 * Time complexity = O(n * log(max(arr)))
 * Space complexity = O(1)
 */
int smallest_divisor_optimal(vector<int> &arr, int k)
{
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long total = calc_sum(arr, mid);

        if (total <= k)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

// check ceil
long long calc_sum(vector<int> &arr, int divisor)
{
    long long sum = 0;
    for (int x : arr)
        sum += (x + divisor - 1) / divisor;
    return sum;
}