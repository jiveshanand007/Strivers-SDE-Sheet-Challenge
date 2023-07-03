#include <bits/stdc++.h>
string longestPalinSubstring(string str)
{
    int n = str.length();
    int start = 0, maxLen = 1;
    vector<vector<int>> table(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        table[i][i] = 1;
    }
    int miniStart = 0;
    for (int i = n - 1; i > 0; i--)
    {
        if (str[i - 1] == str[i])
        {
            table[i - 1][i] = 1;
            start = i - 1;
            maxLen = 2;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (table[i + 1][j - 1] == 1 && str[i] == str[j])
            {
                table[i][j] = 1;
                if (k > maxLen)
                {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }
    return str.substr(start, maxLen);
}