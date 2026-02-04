#include <bits/stdc++.h>

using namespace std;

int largest_element(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {3, 2, 1, 5, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << largest_element(arr, size) << endl;

    return 0;
}

int largest_element(int *arr, int n)
{
    if (n <= 1)
    {
        return arr[0];
    }

    int max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    return max;
}
