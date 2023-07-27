#include <bits/stdc++.h>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    vector<vector<int>> adj(v);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }
    vector<int> indegree(v);
    for (int i = 0; i < v; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    vector<int> topo;
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (int adjNode : adj[node])
        {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0)
                q.push(adjNode);
        }
    }
    return topo;
}