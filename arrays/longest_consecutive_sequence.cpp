#include <bits/stdc++.h>
using namespace std;

int longest_consecutive_sequence_bf(vector<int> &arr);
int longest_consecutive_sequence_better(vector<int> &arr);
int longest_consecutive_sequence_optimal(vector<int> &arr);

int main()
{
    vector<int> arr = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};

    cout << "Longest consecutive (BF): " << longest_consecutive_sequence_bf(arr) << endl;
    cout << "Longest consecutive (Better): " << longest_consecutive_sequence_better(arr) << endl;
    cout << "Longest consecutive (Optimal): " << longest_consecutive_sequence_optimal(arr) << endl;

    return 0;
}

/*
 * Time complexity: O(n²)
 * Space complexity: O(1)
 */
int longest_consecutive_sequence_bf(vector<int> &arr)
{
    int longest = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int count = 1;

        while (true)
        {
            bool found = false;

            // Linear search para el siguiente consecutivo
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == current + 1)
                {
                    found = true;
                    break;
                }
            }

            if (!found)
                break;

            current += 1;
            count++;
        }

        longest = max(longest, count);
    }

    return longest;
}

/*
 * Time complexity: O(n log n)
 * Space complexity: O(1)
 */
int longest_consecutive_sequence_better(vector<int> &arr)
{
    if (arr.empty())
        return 0;

    sort(arr.begin(), arr.end());

    int res = 1, cnt = 1;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] == arr[i - 1])
            continue;

        if (arr[i] == arr[i - 1] + 1)
            cnt++;
        else
            cnt = 1;

        res = max(res, cnt);
    }

    return res;
}

/*
 * Time complexity: O(n)
 * Space complexity: O(n)
 */
int longest_consecutive_sequence_optimal(vector<int> &arr)
{
    unordered_set<int> st;
    int res = 0;

    for (int val : arr)
    {
        st.insert(val);
    }

    for (int val : arr)
    {
        if (st.find(val - 1) == st.end())
        {
            int cur = val, cnt = 0;
            while (st.find(cur) != st.end())
            {
                st.erase(cur);
                cur++;
                cnt++;
            }

            res = max(res, cnt);
        }
    }

    return res;
}