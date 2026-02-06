#include <bits/stdc++.h>

using namespace std;

int find_missing(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 2, 3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << find_missing(arr, size) << endl;

    return 0;
}

int find_missing(int *arr, int n)
{
    int missing = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != missing)
        {
            return missing;
        }
        missing++;
    }

    return missing;
}
