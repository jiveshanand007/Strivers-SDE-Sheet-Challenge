#include <bits/stdc++.h>
bool bfs(int node, vector<int> adj[], vector<int> &col)
{

    queue<int> q;
    q.push(node);
    col[node] = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (int adjNode : adj[frontNode])
        {
            if (col[adjNode] == -1)
            {
                col[adjNode] = !col[frontNode];
                q.push(adjNode);
            }
            else if (col[adjNode] == col[frontNode])
                return false;
        }
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    int n = edges.size();
    int m = edges[0].size();
    vector<int> adj[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (edges[i][j] == 1)
                adj[i].push_back(j), adj[j].push_back(i);
        }
    }
    vector<int> col(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (col[i] == -1)
            if (!bfs(i, adj, col))
                return false;
    }
    return true;
}