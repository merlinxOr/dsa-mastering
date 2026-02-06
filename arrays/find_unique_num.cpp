#include <bits/stdc++.h>

using namespace std;

int find_unique(int *, int);
int find_unique_xor(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 1, 2, 3, 3, 4, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << find_unique(arr, size) << endl;
    cout << find_unique_xor(arr, size) << endl;

    return 0;
}

int find_unique(int *arr, int n)
{
    map<int, int> temp;

    for (int i = 0; i < n; i++)
    {
        temp[arr[i]]++;
    }

    for (auto i : temp)
    {
        if (i.second == 1)
        {
            return i.first;
        }
    }

    return -1;
}

int find_unique_xor(int *arr, int n)
{
    int x = 0;
    for (int i = 0; i < n; i++)
        x ^= arr[i];
    return x;
}