#include <bits/stdc++.h>

using namespace std;

int second_largest_element(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 2, 4, 7, 7, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << second_largest_element(arr, size) << endl;

    return 0;
}

int second_largest_element(int *arr, int n)
{
    int largest = arr[0];
    int second_largest = -1;

    for (int i = 1; i < n; i++)
    {
        if (largest < arr[i])
        {
            largest = arr[i];
        }
        else if (arr[i] > second_largest && arr[i] < largest)
        {
            second_largest = arr[i];
        }
    }

    return second_largest;
}
