#include <bits/stdc++.h>
using namespace std;

void next_permutation_bf(vector<int> &);
void next_permutation_inbuilt(vector<int> &);
void next_permutation_optimal(int *, int);

int main()
{
    vector<int> arr = {2, 4, 1, 7, 5, 0};

    next_permutation_bf(arr);
    // next_permutation_inbuilt(arr);
    // next_permutation_optimal(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void generatePermutations(vector<vector<int>> &res,
                          vector<int> &arr, int idx)
{
    if (idx == arr.size() - 1)
    {
        res.push_back(arr);
        return;
    }

    for (int i = idx; i < arr.size(); i++)
    {
        swap(arr[idx], arr[i]);
        generatePermutations(res, arr, idx + 1);
        swap(arr[idx], arr[i]);
    }
}

/*
 * Time complexity: O(n! * n)
 * Space complexity: O(n! * n)
 */
void next_permutation_bf(vector<int> &arr)
{
    vector<vector<int>> res;

    generatePermutations(res, arr, 0);

    sort(res.begin(), res.end());

    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == arr)
        {
            if (i < res.size() - 1)
            {
                arr = res[i + 1];
            }
            else
            {
                arr = res[0];
            }

            break;
        }
    }
}

/*
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
void next_permutation_inbuilt(vector<int> &arr)
{
    next_permutation(arr.begin(), arr.end());
}

/*
 * Time complexity: O(n)
 * Space complexity: O(1)
 */
void next_permutation_optimal(vector<int> &arr)
{

    int n = arr.size();

    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        reverse(arr.begin(), arr.end());
        return;
    }

    for (int i = n - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    reverse(arr.begin() + pivot + 1, arr.end());
}