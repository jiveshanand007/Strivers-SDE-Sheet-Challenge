#include <bits/stdc++.h>
bool isSafe(int col, int node, vector<int> &color, int n, vector<vector<int>> &mat)
{

    for (int k = 0; k < n; k++)
    {
        if (k != node && mat[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}
bool solve(int node, vector<int> &color, int m, int n, vector<vector<int>> &mat)
{
    if (node == n)
        return true;

    for (int i = 1; i <= m; i++)
    {
        if (isSafe(i, node, color, n, mat))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, mat))
                return true;
            else
                color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> color(n, 0);
    return solve(0, color, m, n, mat) ? "YES" : "NO";
}