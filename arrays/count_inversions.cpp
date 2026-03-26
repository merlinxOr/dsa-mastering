#include <bits/stdc++.h>
using namespace std;

int inversion_count_bf(vector<int> &nums);
int inversion_count_optimal(vector<int> &nums);

int main()
{
    vector<int> nums = {4, 3, 2, 1};

    int res = inversion_count_optimal(nums);

    cout << res << endl;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
int inversion_count_bf(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] > nums[j])
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
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);

    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    int cnt = 0;

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            cnt += (n1 - i);
        }
    }

    while (i < n1)
        arr[k++] = left[i++];

    while (j < n2)
        arr[k++] = right[j++];

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

int inversion_count_optimal(vector<int> &nums)
{
    return merge_sort_count(nums, 0, nums.size() - 1);
}