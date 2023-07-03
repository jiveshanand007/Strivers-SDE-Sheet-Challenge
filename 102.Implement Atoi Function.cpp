#include <bits/stdc++.h>
int atoi(string s)
{
    int n = s.length();

    int i = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    int pos = 0, neg = 0;
    if (s[i] == '-')
    {
        neg++;
        i++;
    }
    if (s[i] == '+')
    {
        pos++;
        i++;
    }
    double ans = 0;
    while (i < n)
    {
        if (s[i] >= '0' && s[i] <= '9')
            ans = ans * 10 + (s[i] - '0');
        i++;
    }

    if (neg > 0)
        ans = -ans;
    if (pos > 0 && neg > 0)
        return 0;
    if (ans > INT_MAX)
        return INT_MAX;
    if (ans < INT_MIN)
        return INT_MIN;
    return (int)ans;
}