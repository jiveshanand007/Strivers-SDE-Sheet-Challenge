int editDistance(string str1, string str2)
{
    int n = str1.length(), m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int i = 0; i <= m; i++)
        dp[0][i] = i;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
            {
                int del = 1 + dp[i - 1][j];
                int rep = 1 + dp[i - 1][j - 1];
                int ins = 1 + dp[i][j - 1];
                dp[i][j] = min(del, min(rep, ins));
            }
        }
    }
    return dp[n][m];
}