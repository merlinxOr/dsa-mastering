#include <bits/stdc++.h>
using namespace std;

vector<int> spiral_matrix_bf(vector<vector<int>> &mat);
vector<int> spiral_matrix_better(vector<vector<int>> &mat);
vector<int> spiral_matrix_optimal(vector<vector<int>> &mat);

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(n²)
 */
vector<int> spiral_matrix_bf(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<int> ans;

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};

    int r = 0, c = 0, di = 0;

    for (int i = 0; i < n * m; i++)
    {
        ans.push_back(mat[r][c]);
        vis[r][c] = 1;

        int nr = r + dr[di];
        int nc = c + dc[di];

        if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc])
        {
            r = nr;
            c = nc;
        }
        else
        {
            di = (di + 1) % 4;
            r += dr[di];
            c += dc[di];
        }
    }

    return ans;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
vector<int> spiral_matrix_better(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    vector<int> ans;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }

    return ans;
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
vector<int> spiral_matrix_optimal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> ans;
    ans.reserve(n * m);

    int left = 0, right = m - 1;
    int top = 0, bottom = n - 1;

    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(mat[top][i]);
        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(mat[bottom][i]);
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }

    return ans;
}