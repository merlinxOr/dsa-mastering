#include <bits/stdc++.h>
using namespace std;

int upper_bound_bf(vector<int> &nums, int target);
int upper_bound_optimal(vector<int> &nums, int target);
int upper_bound_stl(vector<int> &nums, int target);

int main()
{
    vector<int> nums = {2, 3, 7, 10, 11, 11, 25};
    int target = 11;

    int res = upper_bound_optimal(nums, target);

    cout << res << endl;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int upper_bound_bf(vector<int> &nums, int target)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > target)
            return i;
    }

    return n;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int upper_bound_optimal(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int res = nums.size();

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > target)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int upper_bound_stl(vector<int> &nums, int target)
{
    return upper_bound(nums.begin(), nums.end(), target) - nums.begin();
}