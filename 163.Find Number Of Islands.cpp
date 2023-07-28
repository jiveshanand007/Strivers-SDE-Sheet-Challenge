#include <bits/stdc++.h>

void dfs(int row, int col, vector<vector<bool>> &vis, int **arr, int n, int m)
{
    vis[row][col] = true;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int nrow = row + i;
            int ncol = col + j;

            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && arr[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, arr, n, m);
            }
        }
    }
}

int getTotalIslands(int **arr, int n, int m)
{
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && arr[i][j] == 1)
            {
                dfs(i, j, vis, arr, n, m);
                cnt++;
            }
        }
    }
    return cnt;
}
