#include <bits/stdc++.h>
using namespace std;

vector<int> majority_element_bf(vector<int> &nums);
vector<int> majority_element_optimal(vector<int> &nums);

int main()
{
    vector<int> nums = {2, 2, 3, 1, 3, 2, 1, 1};

    vector<int> res = majority_element_optimal(nums);

    for (auto x : res)
        cout << x << " ";
}

/*
 * Time complexity = O(n^2)
 * Space complexity = O(1)
 */
vector<int> majority_element_bf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        if (find(res.begin(), res.end(), nums[i]) != res.end())
            continue;

        for (int j = 0; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }

        if (count > n / 3)
            res.push_back(nums[i]);
    }

    sort(res.begin(), res.end());
    return res;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
vector<int> majority_element_optimal(vector<int> &nums)
{
    int n = nums.size();

    int el1 = INT_MIN, el2 = INT_MIN;
    int cnt1 = 0, cnt2 = 0;

    // 1st pass: find candidates
    for (int num : nums)
    {
        if (num == el1)
            cnt1++;
        else if (num == el2)
            cnt2++;
        else if (cnt1 == 0)
        {
            el1 = num;
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            el2 = num;
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // 2nd pass: verify
    cnt1 = cnt2 = 0;

    for (int num : nums)
    {
        if (num == el1)
            cnt1++;
        else if (num == el2)
            cnt2++;
    }

    vector<int> res;

    if (cnt1 > n / 3)
        res.push_back(el1);
    if (cnt2 > n / 3)
        res.push_back(el2);

    sort(res.begin(), res.end());
    return res;
}