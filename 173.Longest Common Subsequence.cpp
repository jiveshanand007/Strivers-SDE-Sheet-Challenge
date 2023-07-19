#include <bits/stdc++.h>

int f(int i1, int i2, string s, string t, vector<vector<int>> &dp)
{
    if (i1 == s.length() || i2 == t.length())
        return 0;

    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    int take = 0, notTake = 0;

    if (s[i1] == t[i2])
    {
        take = 1 + f(i1 + 1, i2 + 1, s, t, dp);
    }
    notTake = max(f(i1 + 1, i2, s, t, dp), f(i1, i2 + 1, s, t, dp));

    return dp[i1][i2] = max(take, notTake);
}
int lcs(string s, string t)
{
    int n = s.size(), m = t.size();
    vector<int> curr(m + 1, 0), prev(m + 1, 0);

    for (int i1 = n - 1; i1 >= 0; i1--)
    {
        for (int i2 = m - 1; i2 >= 0; i2--)
        {
            int take = 0, notTake = 0;

            if (s[i1] == t[i2])
            {
                take = 1 + prev[i2 + 1];
            }
            notTake = max(prev[i2], curr[i2 + 1]);

            curr[i2] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[0];
}