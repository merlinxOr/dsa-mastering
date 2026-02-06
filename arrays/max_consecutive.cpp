#include <bits/stdc++.h>

using namespace std;

int max_consecutive(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << max_consecutive(arr, size) << endl;

    return 0;
}

int max_consecutive(int *arr, int n)
{
    int count = 0, largest = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            count++;
            largest = max(largest, count);
        }
        else
        {
            count = 0;
        }
    }

    return largest;
}
