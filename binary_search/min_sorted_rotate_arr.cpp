#include <bits/stdc++.h>
using namespace std;

int find_min_bf(vector<int> &nums);
int find_min_optimal(vector<int> &nums);

int main()
{
    vector<int> nums = {5, 6, 1, 2, 3, 4};

    int res = find_min_optimal(nums);

    cout << res << endl;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int find_min_bf(vector<int> &nums)
{
    int mini = nums[0];

    for (int x : nums)
        mini = min(mini, x);

    return mini;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int find_min_optimal(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        if (nums[low] < nums[high])
            return nums[low];

        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }

    return nums[low];
}