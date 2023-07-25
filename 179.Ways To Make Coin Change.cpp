#include <vector>
long exchange(int idx, int val, int *denominations, vector<vector<long>> &dp)
{
    if (idx == 0)
    {
        if (val % denominations[0] == 0)
            return 1;
        return 0;
    }

    if (dp[idx][val] != -1)
        return dp[idx][val];
    long notTake = exchange(idx - 1, val, denominations, dp);
    long take = 0;
    if (denominations[idx] <= val)
    {
        take = exchange(idx, val - denominations[idx], denominations, dp);
    }

    return dp[idx][val] = take + notTake;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return exchange(n - 1, value, denominations, dp);
}