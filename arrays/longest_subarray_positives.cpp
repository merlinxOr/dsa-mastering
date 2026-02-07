#include <bits/stdc++.h>

using namespace std;

int longest_subarray_brute(int *, int, int);
int longest_subarray_hashmap(int *, int, int);
int longest_subarray_sliding(int *, int, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << longest_subarray_brute(arr, size, 3) << endl;
    cout << longest_subarray_hashmap(arr, size, 3) << endl;
    cout << longest_subarray_sliding(arr, size, 6) << endl;

    return 0;
}

int longest_subarray_brute(int *arr, int n, int k)
{
    int longest = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum <= k)
            {
                int length = j - i + 1;
                longest = max(longest, length);
            }
            else
            {
                break;
            }
        }
    }

    return longest;
}

/*
 * Perfect for positive  and negative nums
 */
int longest_subarray_hashmap(int *arr, int n, int k)
{
    map<long long, int> temp;

    long long sum = 0;
    int max_leng = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            max_leng = max(max_leng, i + 1);
        }

        long long rem = sum - k;
        if (temp.find(rem) != temp.end())
        {
            int len = i - temp[rem];
            max_leng = max(max_leng, len);
        }
        if (temp.find(sum) == temp.end())
        {
            temp[sum] = i;
        }
    }

    return max_leng;
}

/*
 * Perfect for positive nums
 */

int longest_subarray_sliding(int *arr, int n, int k)
{
    int max_leng = 0;
    int left = 0;
    int right = 0;
    long long sum = 0;

    while (right < n)
    {
        while (sum > k && left <= right)
        {
            sum -= arr[left++];
        }

        if (sum == k)
        {
            max_leng = max(max_leng, right - left + 1);
        }

        right++;

        if (right < n)
        {
            sum += arr[right];
        }
    }

    return max_leng;
}