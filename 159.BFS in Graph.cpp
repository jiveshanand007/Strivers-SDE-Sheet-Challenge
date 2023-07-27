#include <bits/stdc++.h>
void bfss(int i, vector<int> adj[], vector<bool> &vis, vector<int> &ans)
{
    queue<int> q;
    q.push(i);
    vis[i] = true;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                vis[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    vector<bool> vis(vertex, false);
    vector<int> adj[vertex];
    for (auto i : edges)
    {
        adj[i.first].push_back(i.second);
        adj[i.second].push_back(i.first);
    }

    for (int i = 0; i < vertex; i++)
    {

        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> ans;
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            bfss(i, adj, vis, ans);
        }
    }

    return ans;
}