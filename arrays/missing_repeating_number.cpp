#include <bits/stdc++.h>
using namespace std;

vector<int> find_using_hash(vector<int> &nums);
vector<int> find_using_marking(vector<int> &nums);
vector<int> find_using_math(vector<int> &nums);
vector<int> find_using_xor(vector<int> &nums);

int main()
{
    vector<int> nums = {4, 3, 6, 2, 1, 1};

    vector<int> res = find_using_xor(nums);

    cout << "Repeating: " << res[0] << endl;
    cout << "Missing: " << res[1] << endl;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(n)
 */
vector<int> find_using_hash(vector<int> &nums)
{
    int n = nums.size();
    vector<int> freq(n + 1, 0);

    int repeating = -1, missing = -1;

    for (int x : nums)
        freq[x]++;

    for (int i = 1; i <= n; i++)
    {
        if (freq[i] == 0)
            missing = i;
        else if (freq[i] == 2)
            repeating = i;
    }

    return {repeating, missing};
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
vector<int> find_using_marking(vector<int> &nums)
{
    int n = nums.size();
    int repeating = -1, missing = -1;

    for (int i = 0; i < n; i++)
    {
        int val = abs(nums[i]);

        if (nums[val - 1] < 0)
            repeating = val;
        else
            nums[val - 1] = -nums[val - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
vector<int> find_using_math(vector<int> &nums)
{
    long long n = nums.size();

    long long sumN = n * (n + 1) / 2;
    long long sumSqN = n * (n + 1) * (2 * n + 1) / 6;

    long long sum = 0, sumSq = 0;

    for (int x : nums)
    {
        sum += x;
        sumSq += 1LL * x * x;
    }

    long long diff = sum - sumN;       // A - B
    long long sqDiff = sumSq - sumSqN; // A^2 - B^2

    long long sumAB = sqDiff / diff; // A + B

    int repeating = (diff + sumAB) / 2;
    int missing = sumAB - repeating;

    return {repeating, missing};
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
vector<int> find_using_xor(vector<int> &nums)
{
    int n = nums.size();
    int xr = 0;

    for (int i = 0; i < n; i++)
    {
        xr ^= nums[i];
        xr ^= (i + 1);
    }

    int bit = xr & ~(xr - 1);

    int x = 0, y = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] & bit)
            x ^= nums[i];
        else
            y ^= nums[i];

        if ((i + 1) & bit)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }

    int count = 0;
    for (int num : nums)
        if (num == x)
            count++;

    if (count == 2)
        return {x, y};
    else
        return {y, x};
}
