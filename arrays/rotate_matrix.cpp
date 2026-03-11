#include <bits/stdc++.h>
using namespace std;

void rotate_matrix_bf(vector<vector<int>> &mat);
void rotate_matrix_better(vector<vector<int>> &mat);
void rotate_matrix_optimal(vector<vector<int>> &mat);

int main()
{
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};

    // rotate_matrix_bf(matrix);
    //  rotate_matrix_better(matrix);
    rotate_matrix_optimal(matrix);

    for (auto row : matrix)
    {
        for (auto val : row)
            cout << val << " ";
        cout << endl;
    }
}

/*
 * Time complexity = O(n³)
 * Space complexity = O(n²)
 */
void rotate_matrix_bf(vector<vector<int>> &mat)
{
    int n = mat.size();
    vector<vector<int>> temp(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j][n - i - 1] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = temp[i][j];
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
void rotate_matrix_better(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

/*
 * Time complexity = O(n²)
 * Space complexity = O(1)
 */
void rotate_matrix_optimal(vector<vector<int>> &mat)
{
    int n = mat.size();

    for (int layer = 0; layer < n / 2; layer++)
    {
        int first = layer;
        int last = n - layer - 1;

        for (int i = first; i < last; i++)
        {
            int offset = i - first;

            int top = mat[first][i];
            mat[first][i] = mat[last - offset][first];
            mat[last - offset][first] = mat[last][last - offset];
            mat[last][last - offset] = mat[i][last];
            mat[i][last] = top;
        }
    }
}