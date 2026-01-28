#include <bits/stdc++.h>

using namespace std;

unordered_map<int, int> frequency(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 3, 1, 2, 5, 8, 9, 3, 4, 5, 6, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> result = frequency(arr, size);

    for (auto i : result)
    {
        cout << i.first << " - " << i.second << endl;
    }

    return 0;
}

unordered_map<int, int> frequency(int *arr, int size)
{
    unordered_map<int, int> mpp;

    for (int i = 0; i < size; i++)
    {
        mpp[arr[i]]++;
    }

    return mpp;
}
