int findCost(int idx, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return price[0] * n;
    }
    if (dp[idx][n] != -1)
        return dp[idx][n];
    int notTake = findCost(idx - 1, n, price, dp);

    int take = 0;
    int rodLen = idx + 1;
    if (rodLen <= n)
    {
        take = price[idx] + findCost(idx, n - rodLen, price, dp);
    }

    return dp[idx][n] = max(notTake, take);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return findCost(n - 1, n, price, dp);
}
