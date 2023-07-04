#include <bits/stdc++.h>
string writeAsYouSpeak(int n)
{
    if (n == 1)
        return "1";

    string s = writeAsYouSpeak(n - 1);
    int cnt = 1;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            cnt++;
        }
        else
        {
            ans += (char)(cnt + '0');
            ans += s[i];
            cnt = 1;
        }
    }
    return ans;
}