#include <bits/stdc++.h>
using namespace std;

bool four_sum_bf(vector<int> &nums, int target);
bool four_sum_optimal(vector<int> &nums, int target);

int main()
{
    vector<int> nums = {10, 20, 30, 40, 1, 2};
    int target = 91;

    bool res = four_sum_optimal(nums, target);

    cout << (res ? "true" : "false") << endl;
}

/*
 * Time complexity = O(n⁴)
 * Space complexity = O(1)
 */
bool four_sum_bf(vector<int> &nums, int target)
{
    int n = nums.size();

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            for (int k = j + 1; k < n - 1; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] == target)
                        return true;
                }
            }
        }
    }

    return false;
}

/*
 * Time complexity = O(n³)
 * Space complexity = O(1)
 */
bool four_sum_optimal(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int sum = nums[i] + nums[j] + nums[left] + nums[right];

                if (sum == target)
                    return true;
                else if (sum < target)
                    left++;
                else
                    right--;
            }
        }
    }

    return false;
}