#include <bits/stdc++.h>
using namespace std;

int ship_capacity_bf(vector<int> &weights, int d);
int ship_capacity_optimal(vector<int> &weights, int d);

int required_days(vector<int> &weights, int capacity);

int main()
{
    vector<int> weights = {1, 2, 3, 4, 5, 6, 7};
    int d = 5;

    int res = ship_capacity_optimal(weights, d);

    cout << res << endl;
}

/*
 * Time complexity = O(n * sum(weights))
 * Space complexity = O(1)
 */
int ship_capacity_bf(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    for (int cap = low; cap <= high; cap++)
    {
        if (required_days(weights, cap) <= d)
            return cap;
    }

    return -1;
}

/*
 * Time complexity = O(n * log(sum(weights)))
 * Space complexity = O(1)
 */
int ship_capacity_optimal(vector<int> &weights, int d)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int days = required_days(weights, mid);

        if (days <= d)
        {
            ans = mid;      // possible answer
            high = mid - 1; // try smaller capacity
        }
        else
        {
            low = mid + 1; // need more capacity
        }
    }

    return ans;
}

/*
 * calculate number of days needed with given capacity
 */
int required_days(vector<int> &weights, int capacity)
{
    int days = 1;
    int load = 0;

    for (int w : weights)
    {
        if (load + w > capacity)
        {
            days++;
            load = w;
        }
        else
        {
            load += w;
        }
    }

    return days;
}