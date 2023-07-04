#include <bits/stdc++.h>
vector<int> kmpAlgo(string input, int m)
{
    vector<int> lps(m);
    lps[0] = 0;

    for (int i = 1; i < m; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && input[i] != input[j])
        {
            j = lps[j - 1];
        }
        if (input[i] == input[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}
bool findPattern(string target, string source)
{
    int n = source.size(), m = target.size();
    vector<int> lpsArr = kmpAlgo(target, m);
    int i = 0, j = 0;

    while (i < n)
    {
        if (source[i] == target[j])
        {
            i++, j++;
        }
        else
        {
            if (j > 0)
                j = lpsArr[j - 1];
            else
                i++;
        }
        if (j == m)
        {
            return true;
        }
    }
    return false;
}