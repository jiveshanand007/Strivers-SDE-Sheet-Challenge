int findItems(int idx, int wei, vector<int> &values, vector<int> &weights,
              int n, int w, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (weights[0] <= wei)
            return values[0];
        return 0;
    }

    if (dp[idx][wei] != -1)
        return dp[idx][wei];
    int notTake = findItems(idx - 1, wei, values, weights, n, w, dp);
    int take = 0;

    if (weights[idx] <= wei)
    {
        take = values[idx] + findItems(idx - 1, wei - weights[idx], values, weights, n, w, dp);
    }
    return dp[idx][wei] = max(take, notTake);
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    // vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    // return findItems(n-1,w,values,weights,n,w,dp);

    vector<vector<int>> dp(n, vector<int>(w + 1, 0));

    for (int i = weights[0]; i <= w; i++)
    {
        dp[0][i] = values[0];
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int wei = 0; wei <= w; wei++)
        {
            int notTake = dp[idx - 1][wei];
            int take = 0;

            if (weights[idx] <= wei)
            {
                take = values[idx] + dp[idx - 1][wei - weights[idx]];
            }
            dp[idx][wei] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}