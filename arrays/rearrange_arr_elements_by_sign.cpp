#include <bits/stdc++.h>
using namespace std;

void rearrange_elements_sign_bf(int *, int);
vector<int> rearrange_elements_sign_optimal(int *, int);

int main()
{
    int arr[] = {3, 1, -2, -5, 2, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Brute Force:\n";
    rearrange_elements_sign_bf(arr, size);

    cout << "\nOptimal:\n";
    vector<int> result = rearrange_elements_sign_optimal(arr, size);

    for (int x : result)
        cout << x << " ";

    return 0;
}

/*
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
void rearrange_elements_sign_bf(int *arr, int n)
{
    vector<int> positives;
    vector<int> negatives;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            negatives.push_back(arr[i]);
        else
            positives.push_back(arr[i]);
    }

    vector<int> result(n);
    int i = 0, p = 0, ne = 0;

    while (p < positives.size() && ne < negatives.size())
    {
        result[i++] = positives[p++];
        result[i++] = negatives[ne++];
    }

    while (p < positives.size())
        result[i++] = positives[p++];

    while (ne < negatives.size())
        result[i++] = negatives[ne++];

    for (int x : result)
        cout << x << " ";
}

/*
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
vector<int> rearrange_elements_sign_optimal(int *arr, int n)
{
    vector<int> result(n);

    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            result[neg] = arr[i];
            neg += 2;
        }
        else
        {
            result[pos] = arr[i];
            pos += 2;
        }
    }

    return result;
}