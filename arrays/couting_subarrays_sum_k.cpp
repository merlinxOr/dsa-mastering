#include <bits/stdc++.h>
using namespace std;

int subarrays_sum_bf(vector<int> &nums, int k);
int subarrays_sum_optimal(vector<int> &nums, int k);

int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 2;

    int res = subarrays_sum_optimal(nums, k);

    cout << res << endl;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
int subarrays_sum_bf(vector<int> &nums, int k)
{
    int n = nums.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == k)
                res++;
        }
    }

    return res;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(n)
 */
int subarrays_sum_optimal(vector<int> &arr, int k)
{
    unordered_map<int, int> prefixSums;

    int res = 0;
    int currSum = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];

        if (currSum == k)
            res++;

        if (prefixSums.find(currSum - k) != prefixSums.end())
            res += prefixSums[currSum - k];

        prefixSums[currSum]++;
    }

    return res;
}