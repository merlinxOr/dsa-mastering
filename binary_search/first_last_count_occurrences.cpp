#include <bits/stdc++.h>
using namespace std;

pair<int, int> first_last_bf(vector<int> &nums, int target);
pair<int, int> first_last_optimal(vector<int> &nums, int target);
pair<int, int> first_last_using_bounds(vector<int> &nums, int target);

int find_first(vector<int> &nums, int target);
int find_last(vector<int> &nums, int target);

int main()
{
    vector<int> nums = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int target = 5;

    auto res = first_last_optimal(nums, target);

    cout << "First: " << res.first << endl;
    cout << "Last: " << res.second << endl;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
pair<int, int> first_last_bf(vector<int> &nums, int target)
{
    int first = -1, last = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == target)
        {
            if (first == -1)
                first = i;
            last = i;
        }
    }

    return {first, last};
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int find_first(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int res = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            res = mid;
            high = mid - 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

int find_last(vector<int> &nums, int target)
{
    int low = 0, high = nums.size() - 1;
    int res = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            res = mid;
            low = mid + 1;
        }
        else if (nums[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return res;
}

pair<int, int> first_last_optimal(vector<int> &nums, int target)
{
    return {find_first(nums, target), find_last(nums, target)};
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
pair<int, int> first_last_using_bounds(vector<int> &nums, int target)
{
    int first = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    int last = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if (first >= nums.size() || nums[first] != target)
        return {-1, -1};

    return {first, last};
}