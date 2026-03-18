#include <bits/stdc++.h>
using namespace std;

int largest_subarray_bf(vector<int> &nums);
int largest_subarray_optimal(vector<int> &nums);

int main()
{
    vector<int> nums = {15, -2, 2, -8, 1, 7, 10};

    int res = largest_subarray_optimal(nums);

    cout << res << endl;
}

/*
 * Time complexity = O(n^2)
 * Space complexity = O(1)
 */
int largest_subarray_bf(vector<int> &nums)
{
    int n = nums.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += nums[j];

            if (sum == 0)
                maxLen = max(maxLen, j - i + 1);
        }
    }

    return maxLen;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(n)
 */
int largest_subarray_optimal(vector<int> &nums)
{
    unordered_map<int, int> prefixMap;

    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == 0)
            maxLen = i + 1;

        if (prefixMap.find(sum) != prefixMap.end())
        {
            maxLen = max(maxLen, i - prefixMap[sum]);
        }
        else
        {
            prefixMap[sum] = i;
        }
    }

    return maxLen;
}