#include <bits/stdc++.h>
vector<int> maxMinWindow(vector<int> a, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans(n, INT_MIN), leftSmall(n, 0), rightSmall(n, n - 1);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (!s.empty())
            leftSmall[i] = s.top() + 1;
        s.push(i);
    }
    while (!s.empty())
        s.pop();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && a[s.top()] >= a[i])
            s.pop();
        if (!s.empty())
            rightSmall[i] = s.top() - 1;
        s.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        ans[rightSmall[i] - leftSmall[i]] = max(a[i], ans[rightSmall[i] - leftSmall[i]]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
    return ans;
}