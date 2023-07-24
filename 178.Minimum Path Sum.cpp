#include <bits/stdc++.h>
int minSumPath(vector<vector<int>> &grid)
{
    // int n = grid.size();
    // int m = grid[0].size();
    // vector<vector<int>> dp(n, vector<int>(m, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (i == 0 && j == 0)
    //             dp[i][j] = grid[i][j];
    //         else
    //         {

    //             int down = grid[i][j];
    //             if (i > 0)
    //                 down += dp[i - 1][j];
    //             else
    //                 down += 1e9;
    //             int right = grid[i][j];
    //             if (j > 0)
    //                 right += +dp[i][j - 1];
    //             else
    //                 right += 1e9;

    //             dp[i][j] = min(down, right);
    //         }
    //     }

    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int up = grid[i][j], left = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;
                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 1e9;
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n - 1];

    // return dp[n - 1][m - 1];
}