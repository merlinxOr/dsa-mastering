#include <bits/stdc++.h>
using namespace std;

bool triplet_sum_bf(vector<int> &nums, int target);
bool triplet_sum_optimal(vector<int> &nums, int target);

int main()
{
    vector<int> nums = {1, 4, 45, 6, 10, 8};
    int target = 13;

    bool res = triplet_sum_optimal(nums, target);

    cout << (res ? "true" : "false") << endl;
}

/*
 * Time complexity = O(n³)
 * Space complexity = O(1)
 */
bool triplet_sum_bf(vector<int> &nums, int target)
{
    int n = nums.size();

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (nums[i] + nums[j] + nums[k] == target)
                    return true;
            }
        }
    }

    return false;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
bool triplet_sum_optimal(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++)
    {
        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == target)
                return true;
            else if (sum < target)
                left++;
            else
                right--;
        }
    }

    return false;
}