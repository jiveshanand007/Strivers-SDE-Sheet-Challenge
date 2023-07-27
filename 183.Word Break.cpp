#include <bits/stdc++.h>
bool wordBreak(vector<string> &arr, int n, string &target)
{
    vector<bool> dp(target.size() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= target.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && (find(arr.begin(), arr.end(), target.substr(j, i - j)) != arr.end()))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[target.size()];
}