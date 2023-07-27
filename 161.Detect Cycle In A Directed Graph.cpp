#include <bits/stdc++.h>
bool checkCycle(int node, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &adj)
{
    vis[node] = true;
    pathVis[node] = true;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (checkCycle(adjNode, vis, pathVis, adj))
                return true;
        }
        else if (pathVis[adjNode])
            return true;
    }
    pathVis[node] = false;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> pathVis(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, vis, pathVis, adj))
                return true;
        }
    }
    return false;
}
