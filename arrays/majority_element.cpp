#include <bits/stdc++.h>
using namespace std;

int majority_element_bf(vector<int> &);
int majority_element_better(vector<int> &);
int majority_element_optimal(vector<int> &);

int main()
{
    vector<int> nums = {2, 2, 3, 3, 1, 2, 2};

    cout << majority_element_bf(nums) << endl;
    cout << majority_element_better(nums) << endl;
    cout << majority_element_optimal(nums) << endl;

    return 0;
}

/*
 * Time complexity: O(n²)
 * Space complexity: O(1)
 */
int majority_element_bf(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        if (count > n / 2)
            return nums[i];
    }

    return -1;
}

/*
 * Time complexity: O(n log n)
 * Space complexity: O(n)
 */
int majority_element_better(vector<int> &nums)
{
    map<int, int> mpp;

    for (int i = 0; i < nums.size(); i++)
    {
        mpp[nums[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > (nums.size() / 2))
        {
            return it.first;
        }
    }

    return -1;
}

/*
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
int majority_element_optimal(vector<int> &nums)
{
    int count = 0;
    int candidate = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            candidate = nums[i];
            count = 1;
        }
        else if (nums[i] == candidate)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == candidate)
            cnt++;
    }

    return (cnt > nums.size() / 2) ? candidate : -1;
}
