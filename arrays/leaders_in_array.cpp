#include <bits/stdc++.h>
using namespace std;

vector<int> leaders_bf(vector<int> &arr);
vector<int> leaders_optimal(vector<int> &arr);

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};

    vector<int> res_bf = leaders_bf(arr);
    cout << "Leaders (Brute Force): ";
    for (int x : res_bf)
        cout << x << " ";
    cout << endl;

    vector<int> res_opt = leaders_optimal(arr);
    cout << "Leaders (Optimal): ";
    for (int x : res_opt)
        cout << x << " ";
    cout << endl;

    return 0;
}

/*
 * Time complexity: O(n²)
 * Space complexity: O(n)
 */
vector<int> leaders_bf(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();
    int j;

    for (int i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                break;
            }
        }

        if (j == n)
        {
            res.push_back(arr[i]);
        }
    }

    return res;
}

/*
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
vector<int> leaders_optimal(vector<int> &arr)
{
    vector<int> res;
    int n = arr.size();

    int maxRight = arr[n - 1];
    res.push_back(maxRight);

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= maxRight)
        {
            maxRight = arr[i];
            res.push_back(maxRight);
        }
    }

    reverse(res.begin(), res.end());
    return res;
}