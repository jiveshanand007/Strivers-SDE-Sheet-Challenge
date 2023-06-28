#include <bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    vector<int> ans(k);
    priority_queue<int> pq;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int sum = a[i] + b[j];
            pq.push(sum);
        }
    }
    for (int i = 0; i < k; i++)
    {
        ans[i] = pq.top();
        pq.pop();
    }
    return ans;
}