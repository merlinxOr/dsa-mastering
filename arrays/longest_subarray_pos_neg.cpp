#include <bits/stdc++.h>

using namespace std;

int longest_subarray(int *, int, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << longest_subarray(arr, size, 3) << endl;

    return 0;
}

/*
 * Perfect for positive  and negative nums
 */
int longest_subarray(int *arr, int n, int k)
{
    map<long long, int> pre_sum;
    long long sum = 0;
    int max_lenght = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            max_lenght = max(max_lenght, i + 1);
        }

        long long rem = sum - k;
        if (pre_sum.find(rem) != pre_sum.end())
        {
            int len = i - pre_sum[rem];
            max_lenght = max(max_lenght, len);
        }
        if (pre_sum.find(sum) == pre_sum.end())
        {
            pre_sum[sum] = i;
        }
    }

    return max_lenght;
}
