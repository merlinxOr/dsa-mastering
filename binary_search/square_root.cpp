#include <bits/stdc++.h>
using namespace std;

int sqrt_bf(int n);
int sqrt_optimal(int n);

int main()
{
    int n = 11;

    int res = sqrt_optimal(n);

    cout << res << endl;
}

/*
 * Time complexity = O(sqrt(n))
 * Space complexity = O(1)
 */
int sqrt_bf(int n)
{
    int i = 1;

    while (i * i <= n)
        i++;

    return i - 1;
}

/*
 * Time complexity = O(log n)
 * Space complexity = O(1)
 */
int sqrt_optimal(int n)
{
    int low = 1, high = n;
    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((long long)mid * mid <= n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return ans;
}