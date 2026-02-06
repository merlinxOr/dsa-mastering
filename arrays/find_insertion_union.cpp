#include <bits/stdc++.h>

using namespace std;

void find_union(int *, int, int *, int);
void find_intersection(int *, int, int *, int);

int main(int argc, char const *argv[])
{

    int arr1[] = {1, 1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5};
    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]);
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]);

    find_union(arr1, size_arr1, arr2, size_arr2);

    int arr3[] = {1, 2, 2, 3, 3, 4, 5, 6};
    int arr4[] = {2, 3, 3, 5, 6, 6, 7};
    int size_arr3 = sizeof(arr3) / sizeof(arr3[0]);
    int size_arr4 = sizeof(arr4) / sizeof(arr4[0]);

    find_intersection(arr3, size_arr3, arr4, size_arr4);

    return 0;
}

void find_union(int *arr1, int n, int *arr2, int m)
{
    vector<int> temp;

    int j = 0;
    int k = 0;

    while (j < n && k < m)
    {
        if (arr1[j] <= arr2[k])
        {
            if ((temp.empty() || temp.back() != arr1[j]))
            {
                temp.push_back(arr1[j]);
            }
            j++;
        }
        else
        {
            if ((temp.empty() || temp.back() != arr2[k]))
            {
                temp.push_back(arr2[k]);
            }
            k++;
        }
    }

    while (j < n)
    {
        if ((temp.empty() || temp.back() != arr1[j]))
        {
            temp.push_back(arr1[j]);
        }
        j++;
    }

    while (k < m)
    {
        if ((temp.empty() || temp.back() != arr2[k]))
        {
            temp.push_back(arr2[k]);
        }
        k++;
    }

    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
}

void find_intersection(int *arr1, int n, int *arr2, int m)
{
    vector<int> temp;

    int i = 0;
    int j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            j++;
        }
        else
        {
            if (temp.empty() || temp.back() != arr1[i])
            {
                temp.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    for (auto i : temp)
    {
        cout << i << " ";
    }
    cout << endl;
}