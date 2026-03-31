#include <bits/stdc++.h>
using namespace std;

int min_eating_speed_bf(vector<int> &piles, int h);
int min_eating_speed_optimal(vector<int> &piles, int h);

long long calculate_hours(vector<int> &piles, int speed);

int main()
{
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    int res = min_eating_speed_optimal(piles, h);

    cout << res << endl;
}

/*
 * Time complexity = O(max(piles) * n)
 * Space complexity = O(1)
 */
int min_eating_speed_bf(vector<int> &piles, int h)
{
    int maxPile = *max_element(piles.begin(), piles.end());

    for (int k = 1; k <= maxPile; k++)
    {
        long long hours = calculate_hours(piles, k);

        if (hours <= h)
            return k;
    }

    return -1;
}

/*
 * Time complexity = O(n log max(piles))
 * Space complexity = O(1)
 */
int min_eating_speed_optimal(vector<int> &piles, int h)
{
    int low = 1;
    int high = *max_element(piles.begin(), piles.end());
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long hours = calculate_hours(piles, mid);

        if (hours <= h)
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
 * H needed for k
 */
long long calculate_hours(vector<int> &piles, int speed)
{
    long long total = 0;

    for (int bananas : piles)
    {
        total += (bananas + speed - 1) / speed; // ceil
    }

    return total;
}