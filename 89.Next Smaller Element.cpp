#include <bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> stk;
    vector<int> ans(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk.empty() && stk.top() >= arr[i])
            stk.pop();
        if (!stk.empty())
            ans[i] = stk.top();
        stk.push(arr[i]);
    }
    return ans;
}