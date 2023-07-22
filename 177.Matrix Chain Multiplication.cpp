#include <bits/stdc++.h>
int findCost(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int ans = findCost(i, k, arr, dp) + findCost(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(mini, ans);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // vector<vector<int>> dp(N,vector<int>(N,-1));
    // return findCost(1,N-1,arr,dp);

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int ans = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                mini = min(mini, ans);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}