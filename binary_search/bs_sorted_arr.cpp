#include <bits/stdc++.h>
using namespace std;

int binary_search_iterative(vector<int> &nums, int target);
int binary_search_recursive(vector<int> &nums, int low, int high, int target);

int main()
{
    vector<int> nums = {2, 3, 4, 10, 40};
    int target = 10;

    int res = binary_search_iterative(nums, target);

    cout << res << endl;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int binary_search_iterative(vector<int> &nums, int target)
{
    int low = 0;
    int high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        else if (nums[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(log n)
 */
int binary_search_recursive(vector<int> &nums, int low, int high, int target)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;

    else if (nums[mid] > target)
        return binary_search_recursive(nums, low, mid - 1, target);

    else
        return binary_search_recursive(nums, mid + 1, high, target);
}