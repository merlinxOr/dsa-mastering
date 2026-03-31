#include <bits/stdc++.h>
using namespace std;

long long min_days_bf(vector<int> &bloomDay, int m, int k);
long long min_days_optimal(vector<int> &bloomDay, int m, int k);

bool can_make(vector<int> &bloomDay, int m, int k, long long days);

int main()
{
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    long long res = min_days_optimal(bloomDay, m, k);

    cout << res << endl;
}

/*
 * Time complexity = O(max(bloomDay) * n)
 * Space complexity = O(1)
 */
long long min_days_bf(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    long long maxDay = *max_element(bloomDay.begin(), bloomDay.end());

    for (long long d = 1; d <= maxDay; d++)
    {
        if (can_make(bloomDay, m, k, d))
            return d;
    }

    return -1;
}

/*
 * Time complexity = O(n log max(bloomDay))
 * Space complexity = O(1)
 */
long long min_days_optimal(vector<int> &bloomDay, int m, int k)
{
    long long low = 1;
    long long high = *max_element(bloomDay.begin(), bloomDay.end());
    long long ans = -1;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;

        if (can_make(bloomDay, m, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

/*
 * verify if with days we could make m bouquets
 */
bool can_make(vector<int> &bloomDay, int m, int k, long long days)
{
    int bouquets = 0;
    int flowers = 0;

    for (int d : bloomDay)
    {
        if (d <= days)
        {
            flowers++;
            if (flowers == k)
            {
                bouquets++;
                flowers = 0;
                if (bouquets == m)
                    return true;
            }
        }
        else
        {
            flowers = 0;
        }
    }

    return false;
}