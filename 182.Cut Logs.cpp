#include <climits>
#include <vector>
int countMoves(int k, int n, vector<vector<int>> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (k == 1)
        return n;

    if (dp[k][n] != -1)
        return dp[k][n];

    int low = 1;
    int high = n;
    int mini = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        int broke = countMoves(k - 1, mid - 1, dp);
        int notBroke = countMoves(k, n - mid, dp);

        int temp = 1 + max(broke, notBroke);
        mini = min(mini, temp);

        if (broke < notBroke)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return dp[k][n] = mini;
}
int cutLogs(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return countMoves(k, n, dp);
}
