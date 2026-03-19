#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge_intervals_bf(vector<vector<int>> &intervals);
vector<vector<int>> merge_intervals_optimal(vector<vector<int>> &intervals);

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> res = merge_intervals_optimal(intervals);

    for (auto &iv : res)
        cout << "[" << iv[0] << ", " << iv[1] << "] ";
    cout << endl;
}

/*
 * Time complexity = O(n^2)
 * Space complexity = O(n)
 */
vector<vector<int>> merge_intervals_bf(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<bool> taken(n, false);
    vector<vector<int>> merged;

    for (int i = 0; i < n; i++)
    {
        if (taken[i])
            continue;

        int start = intervals[i][0];
        int end = intervals[i][1];

        for (int j = i + 1; j < n; j++)
        {
            if (!taken[j] && !(intervals[j][1] < start || intervals[j][0] > end))
            {
                start = min(start, intervals[j][0]);
                end = max(end, intervals[j][1]);
                taken[j] = true;
            }
        }

        merged.push_back({start, end});
    }

    return merged;
}

/*
 * Time complexity = O(n log n)
 * Space complexity = O(n)
 */
vector<vector<int>> merge_intervals_optimal(vector<vector<int>> &intervals)
{
    if (intervals.empty())
        return {};

    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b)
         {
             return a[0] < b[0];
         });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        auto &last = merged.back();

        if (intervals[i][0] <= last[1])
        {
            last[1] = max(last[1], intervals[i][1]);
        }
        else
        {
            merged.push_back(intervals[i]);
        }
    }

    return merged;
}