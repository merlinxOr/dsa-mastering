#include <bits/stdc++.h>

using namespace std;

int remove_duplicated(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 1, 2, 2, 2, 3, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << remove_duplicated(arr, size) << endl;

    return 0;
}

int remove_duplicated(int *arr, int n)
{
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            count++;
        }
    }

    return count;
}
