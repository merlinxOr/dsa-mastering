#include <bits/stdc++.h>

using namespace std;

void tow_sum_bf(int *, int, int);
void tow_sum_hashing(int *, int, int);
void tow_sum_pointers(int *, int, int);

int main(int argc, char const *argv[])
{
    int arr[] = {2, 6, 5, 8, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    tow_sum_bf(arr, size, 14);
    tow_sum_hashing(arr, size, 14);
    tow_sum_pointers(arr, size, 14);
    return 0;
}

void tow_sum_bf(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                cout << arr[i] << " + " << arr[j] << " = " << target << endl;
            }
        }
    }
}

void tow_sum_hashing(int *arr, int n, int target)
{
    map<int, int> seen;

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        if (seen.find(complement) != seen.end())
        {
            cout << arr[i] << " + " << complement << " = " << target << endl;
        }

        seen[arr[i]] = 1;
    }
}

void tow_sum_pointers(int *arr, int n, int target)
{
    sort(arr, arr + n);

    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];

        if (sum > target)
        {
            right--;
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            cout << arr[left] << " + " << arr[right] << " = " << target << endl;
            left++;
            right--;
        }
    }
}
