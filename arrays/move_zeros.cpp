#include <bits/stdc++.h>

using namespace std;

void move_zeros_bf(int *, int);
void move_zeros(int *, int);

int main(int argc, char const *argv[])
{

    int arr[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // move_zeros_bf(arr, size);
    move_zeros(arr, size);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

void move_zeros_bf(int *arr, int n)
{
    int last = n - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 0)
        {
            int j = i;

            while (j < n - 1)
            {
                arr[j] = arr[j + 1];
                j++;
            }
            arr[last--] = 0;
        }
    }
}

void move_zeros(int *arr, int n)
{
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        if (arr[right] != 0)
        {
            swap(arr[left], arr[right]);
            left++;
        }
    }
}
