#include <bits/stdc++.h>
using namespace std;

int subarrays_xor_bf(vector<int> &nums, int k);
int subarrays_xor_optimal(vector<int> &nums, int k);

int main()
{
    vector<int> nums = {4, 2, 2, 6, 4};
    int k = 6;

    int res = subarrays_xor_optimal(nums, k);

    cout << res << endl;
}

/*
 * Time complexity = O(n^2)
 * Space complexity = O(1)
 */
int subarrays_xor_bf(vector<int> &nums, int k)
{
    int n = nums.size();
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        int xr = 0;

        for (int j = i; j < n; j++)
        {
            xr ^= nums[j];

            if (xr == k)
                res++;
        }
    }

    return res;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(n)
 */
int subarrays_xor_optimal(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    int xr = 0;
    int res = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        xr ^= nums[i];

        if (xr == k)
            res++;

        int need = xr ^ k;

        if (freq.find(need) != freq.end())
            res += freq[need];

        freq[xr]++;
    }

    return res;
}