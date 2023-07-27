void dfs(int node, vector<int> adj[], vector<bool> &vis, vector<int> &ans)
{
    vis[node] = true;
    ans.push_back(node);
    for (int adjNode : adj[node])
    {
        if (!vis[adjNode])
        {
            dfs(adjNode, adj, vis, ans);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    vector<int> adj[V];
    for (auto it : edges)
    {
        int a = it[0];
        int b = it[1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> ans;
    vector<bool> vis(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;

            dfs(i, adj, vis, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}