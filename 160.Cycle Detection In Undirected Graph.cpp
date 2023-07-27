bool checkCycle(int node, int parent, vector<bool> &vis, vector<bool> &pathVis, vector<vector<int>> &adj)
{
    vis[node] = true;
    // pathVis[node] = true;
    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            if (checkCycle(adjNode, node, vis, pathVis, adj))
                return true;
        }
        else if (adjNode != parent)
            return true;
    }
    // pathVis[node] = false;
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> pathVis(n, false);

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (checkCycle(i, -1, vis, pathVis, adj))
                return "Yes";
        }
    }
    return "No";
}
