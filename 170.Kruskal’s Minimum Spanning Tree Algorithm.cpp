class disjointSet
{
    vector<int> rank, size, parent;

public:
    disjointSet(int n)
    {
        rank.resize(n + 1);
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUparent(int node)
    {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = findUparent(parent[node]);
    }
    void unionbySize(int u, int v)
    {
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[u] < size[v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int kruskalMST(int n, vector<vector<int>> &edges)
{
    vector<pair<int, pair<int, int>>> adj;

    for (auto it : edges)
    {
        adj.push_back({it[2], {it[0], it[1]}});
    }
    sort(adj.begin(), adj.end());
    disjointSet ds(n);

    int minSt = 0;
    for (it : adj)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUparent(u) != ds.findUparent(v))
        {
            minSt += wt;
            ds.unionbySize(u, v);
        }
    }
    return minSt;
}
