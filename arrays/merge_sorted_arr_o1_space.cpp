#include <bits/stdc++.h>
using namespace std;

void merge_sorted_bf(vector<int> &a, vector<int> &b);
void merge_sorted_optimal(vector<int> &a, vector<int> &b);

int main()
{
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};

    merge_sorted_optimal(a, b);

    for (auto x : a)
        cout << x << " ";
    for (auto x : b)
        cout << x << " ";
    cout << endl;
}

/*
 * Time complexity = O((n + m) log(n + m))
 * Space complexity = O(n + m)
 */
void merge_sorted_bf(vector<int> &a, vector<int> &b)
{
    vector<int> merged;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
            merged.push_back(a[i++]);
        else
            merged.push_back(b[j++]);
    }

    while (i < a.size())
        merged.push_back(a[i++]);
    while (j < b.size())
        merged.push_back(b[j++]);

    for (int k = 0; k < merged.size(); k++)
    {
        if (k < a.size())
            a[k] = merged[k];
        else
            b[k - a.size()] = merged[k];
    }
}

/*
 * Time complexity = O((n + m) log(n + m))
 * Space complexity = O(1)
 */
void merge_sorted_optimal(vector<int> &a, vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    int gap = n + m;

    auto nextGap = [&](int g)
    {
        if (g <= 1)
            return 0;
        return (g / 2) + (g % 2);
    };

    for (gap = nextGap(gap); gap > 0; gap = nextGap(gap))
    {
        int i = 0;
        int j = gap;

        while (j < n + m)
        {
            if (j < n && a[i] > a[j])
                swap(a[i], a[j]);

            else if (i < n && j >= n && a[i] > b[j - n])
                swap(a[i], b[j - n]);

            else if (i >= n && j >= n && b[i - n] > b[j - n])
                swap(b[i - n], b[j - n]);

            i++;
            j++;
        }
    }
}