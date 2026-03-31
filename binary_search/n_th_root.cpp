#include <bits/stdc++.h>
using namespace std;

int nth_root_bf(int n, int m);
int nth_root_optimal(int n, int m);

long long power(int base, int exp, int limit);

int main()
{
    int n = 3, m = 27;

    int res = nth_root_optimal(n, m);

    cout << res << endl;
}

/*
 * Time complexity = O(m^(1/n))
 * Space complexity = O(1)
 */
int nth_root_bf(int n, int m)
{
    for (int i = 1; i <= m; i++)
    {
        long long val = 1;

        for (int j = 0; j < n; j++)
        {
            val *= i;
            if (val > m)
                break;
        }

        if (val == m)
            return i;
    }

    return -1;
}

/*
 * Time complexity = O(log m * n)
 * Space complexity = O(1)
 */
int nth_root_optimal(int n, int m)
{
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long val = power(mid, n, m);

        if (val == m)
            return mid;
        else if (val < m)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

long long power(int base, int exp, int limit)
{
    long long result = 1;

    for (int i = 0; i < exp; i++)
    {
        result *= base;
        if (result > limit)
            return result;
    }

    return result;
}