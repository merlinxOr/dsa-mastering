#include <bits/stdc++.h>
using namespace std;

int reverse_pairs_bf(vector<int> &nums);
int reverse_pairs_optimal(vector<int> &nums);

int main()
{
    vector<int> nums = {3, 2, 4, 5, 1, 20};

    int res = reverse_pairs_optimal(nums);

    cout << res << endl;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
int reverse_pairs_bf(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > 2 * nums[j])
                cnt++;
        }
    }

    return cnt;
}

/*
 * Time complexity = O(n log n)
 * Space complexity = O(n)
 */
int merge_and_count(vector<int> &arr, int l, int m, int r)
{
    int cnt = 0;

    int j = m + 1;
    for (int i = l; i <= m; i++)
    {
        while (j <= r && (long long)arr[i] > 2LL * arr[j])
            j++;

        cnt += (j - (m + 1));
    }

    vector<int> temp;
    int left = l, right = m + 1;

    while (left <= m && right <= r)
    {
        if (arr[left] <= arr[right])
            temp.push_back(arr[left++]);
        else
            temp.push_back(arr[right++]);
    }

    while (left <= m)
        temp.push_back(arr[left++]);
    while (right <= r)
        temp.push_back(arr[right++]);

    for (int i = l; i <= r; i++)
        arr[i] = temp[i - l];

    return cnt;
}

int merge_sort_count(vector<int> &arr, int l, int r)
{
    int cnt = 0;

    if (l < r)
    {
        int m = (l + r) / 2;

        cnt += merge_sort_count(arr, l, m);
        cnt += merge_sort_count(arr, m + 1, r);
        cnt += merge_and_count(arr, l, m, r);
    }

    return cnt;
}

int reverse_pairs_optimal(vector<int> &nums)
{
    return merge_sort_count(nums, 0, nums.size() - 1);
}