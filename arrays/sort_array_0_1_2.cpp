#include <bits/stdc++.h>

using namespace std;

void sort_arr_bf(vector<int> &);
void sort_arr_optimal(vector<int> &);

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    sort_arr_bf(nums);
    sort_arr_optimal(nums);

    for (auto i : nums)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1) in-place
 */
void sort_arr_bf(vector<int> &nums)
{
    int zero = 0;
    int one = 0;
    int two = 0;

    for (auto i : nums)
    {
        if (i == 0)
        {
            zero++;
        }
        else if (i == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (zero > 0)
        {
            nums[i] = 0;
            zero--;
        }
        else if (one > 0)
        {
            nums[i] = 1;
            one--;
        }
        else
        {
            nums[i] = 2;
            two--;
        }
    }
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1) in-place
 */
void sort_arr_optimal(vector<int> &nums)
{
    int low = 0, mid = 0, high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}
