#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    vector<int> ans(k);
    unordered_map<int, int> hash;
    for (int x : arr)
        hash[x]++;

    auto bigger = [&](int i, int j)
    {
        return hash[i] > hash[j];
    };
    priority_queue<int, vector<int>, decltype(bigger)> pq(bigger);

    for (auto it : hash)
    {
        pq.push(it.first);
        if (pq.size() > k)
            pq.pop();
    }
    copy(&(pq.top()), &(pq.top()) + k, &ans[0]);
    sort(ans.begin(), ans.end());
    return ans;
}