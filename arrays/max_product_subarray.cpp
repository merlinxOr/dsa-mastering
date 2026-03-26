#include <bits/stdc++.h>
using namespace std;

int max_product_bf(vector<int> &nums);
int max_product_optimal(vector<int> &nums);
int max_product_two_pass(vector<int> &nums);

int main()
{
    vector<int> nums = {-2, 6, -3, -10, 0, 2};

    int res = max_product_optimal(nums);

    cout << res << endl;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
int max_product_bf(vector<int> &nums)
{
    int n = nums.size();
    int maxProd = nums[0];

    for (int i = 0; i < n; i++)
    {
        int prod = 1;

        for (int j = i; j < n; j++)
        {
            prod *= nums[j];
            maxProd = max(maxProd, prod);
        }
    }

    return maxProd;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int max_product_optimal(vector<int> &nums)
{
    int currMax = nums[0];
    int currMin = nums[0];
    int maxProd = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        int temp = max({nums[i], nums[i] * currMax, nums[i] * currMin});

        currMin = min({nums[i], nums[i] * currMax, nums[i] * currMin});
        currMax = temp;

        maxProd = max(maxProd, currMax);
    }

    return maxProd;
}

/*
 * Time complexity = O(n)
 * Space complexity = O(1)
 */
int max_product_two_pass(vector<int> &nums)
{
    int n = nums.size();
    int maxProd = INT_MIN;

    int leftProd = 1, rightProd = 1;

    for (int i = 0; i < n; i++)
    {
        if (leftProd == 0)
            leftProd = 1;
        if (rightProd == 0)
            rightProd = 1;

        leftProd *= nums[i];
        rightProd *= nums[n - 1 - i];

        maxProd = max({maxProd, leftProd, rightProd});
    }

    return maxProd;
}