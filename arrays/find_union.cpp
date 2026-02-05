#include <bits/stdc++.h>

using namespace std;

void find_union(int *, int, int *, int);

int main(int argc, char const *argv[])
{

    int arr1[] = {1, 1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5};
    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);

    find_union(arr1, size_arr1, arr2, size_arr2);

    return 0;
}

void find_union(int *arr1, int n, int *arr2, int m)
{
    set<int> result;

    for (int i = 0; i < n; i++)
    {
        result.insert(arr1[i]);
    }

    for (int i = 0; i < m; i++)
    {
        result.insert(arr2[i]);
    }

    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << endl;
}
