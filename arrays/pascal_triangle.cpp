#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal_triangle_bf(int n);
vector<vector<int>> pascal_triangle_optimal(int n);

int main()
{
    int n = 5;

    vector<vector<int>> res = pascal_triangle_optimal(n);

    for (auto &row : res)
    {
        for (auto &val : row)
            cout << val << " ";
        cout << endl;
    }
}

/*
 * Time complexity = O(n^3)
 * Space complexity = O(n^2)
 */
int nCr(int n, int r)
{
    int res = 1;

    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }

    return res;
}

vector<vector<int>> pascal_triangle_bf(int n)
{
    vector<vector<int>> triangle;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j <= i; j++)
        {
            row.push_back(nCr(i, j));
        }
        triangle.push_back(row);
    }

    return triangle;
}

/*
 * Time complexity = O(n^2)
 * Space complexity = O(n^2)
 */
vector<vector<int>> pascal_triangle_optimal(int n)
{
    vector<vector<int>> triangle(n);

    for (int i = 0; i < n; i++)
    {
        triangle[i].resize(i + 1);
        triangle[i][0] = triangle[i][i] = 1;

        for (int j = 1; j < i; j++)
        {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }

    return triangle;
}