#include <bits/stdc++.h>
using namespace std;

void set_matrix_zero_bf(vector<vector<int>> &mat);
void set_matrix_zero_better(vector<vector<int>> &mat);
void set_matrix_zero_optimal(vector<vector<int>> &mat);

int main()
{
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};

    set_matrix_zero_optimal(matrix);

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
 * Time complexity = O(n³)
 * Space complexity = O(1)
 */
void set_matrix_zero_bf(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int col = 0; col < m; col++)
                {
                    if (mat[i][col] != 0)
                        mat[i][col] = -1;
                }

                for (int row = 0; row < n; row++)
                {
                    if (mat[row][j] != 0)
                        mat[row][j] = -1;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = 0;
        }
    }
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(n + m)
 */
void set_matrix_zero_better(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    vector<int> row(n, 0);
    vector<int> col(m, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                mat[i][j] = 0;
            }
        }
    }
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
void set_matrix_zero_optimal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int col0 = 1;

    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 0)
            col0 = 0;

        for (int j = 1; j < m; j++)
        {
            if (mat[i][j] == 0)
            {
                mat[i][0] = 0;
                mat[0][j] = 0;
            }
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 1; j--)
        {
            if (mat[i][0] == 0 || mat[0][j] == 0)
            {
                mat[i][j] = 0;
            }
        }

        if (col0 == 0)
        {
            mat[i][0] = 0;
        }
    }
}