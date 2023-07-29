#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<pair<int, int>> adj[vertices];

    for (auto it : vec)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int wt = curr.first;
        int node = curr.second;

        for (auto it : adj[node])
        {
            int edgeW = it.second;
            int adjNode = it.first;
            if (edgeW + wt < dist[adjNode])
            {
                dist[adjNode] = edgeW + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}
