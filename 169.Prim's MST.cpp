#include <bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m,
                                                    vector<pair<pair<int, int>, int>> &g)
{
    // Greedy
    vector<vector<int>> adj[n + 1];
    for (auto it : g)
    {
        adj[it.first.first].push_back({it.first.second, it.second});
        adj[it.first.second].push_back({it.first.first, it.second});
    }
    vector<pair<pair<int, int>, int>> ans;
    priority_queue<pair<pair<int, int>, int>,
                   vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>>
        pq;

    pq.push({{0, 1}, -1});
    vector<int> vis(n + 1, 0);
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        int node = it.first.second;
        int wt = it.first.first;
        int parent = it.second;

        if (vis[node])
            continue;
        vis[node] = 1;
        if (parent != -1)
            ans.push_back({{parent, node}, wt});

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeW = it[1];
            if (!vis[adjNode])
                pq.push({{edgeW, adjNode}, node});
        }
    }
    return ans;
}
