#include <bits/stdc++.h>
using namespace std;

int search_bf(vector<int> &nums, int target);
int search_optimal(vector<int> &nums, int target);
int search_using_pivot(vector<int> &nums, int target);

int binary_search(vector<int> &nums, int low, int high, int target);
int find_pivot(vector<int> &nums);

int main()
{
    vector<int> nums = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    int target = 3;

    int res = search_optimal(nums, target);

    cout << res << endl;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int search_bf(vector<int> &nums, int target)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int search_optimal(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
            return mid;

        // left sorted
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target < nums[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // right sorted
        else
        {
            if (target > nums[mid] && target <= nums[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int binary_search(vector<int> &nums, int low, int high, int target)
{
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

int find_pivot(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] > nums[high])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int search_using_pivot(vector<int> &nums, int target)
{
    int pivot = find_pivot(nums);

    if (nums[pivot] == target)
        return pivot;

    if (pivot == 0)
        return binary_search(nums, 0, nums.size() - 1, target);

    if (target >= nums[0])
        return binary_search(nums, 0, pivot - 1, target);

    return binary_search(nums, pivot, nums.size() - 1, target);
}