#include <bits/stdc++.h>
void solve(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &maze, vector<vector<int>> &ans, int n)
{
    if (i == n - 1 && j == n - 1)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                temp.push_back(vis[j][i]);
        }
        ans.push_back(temp);
        return;
    }

    int dr[] = {0, 1, 0, -1};
    int dc[] = {-1, 0, 1, 0};
    for (int k = 0; k < 4; k++)
    {
        int nr = dr[k] + i;
        int nc = dc[k] + j;

        if (nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc] && maze[nr][nc] == 1)
        {
            vis[nr][nc] = 1;
            solve(nr, nc, vis, maze, ans, n);
            vis[nr][nc] = 0;
        }
    }
}
vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n)
{
    vector<vector<int>> ans, vis(n, vector<int>(n, 0));
    if (maze[0][0])
    {
        vis[0][0] = 1;
        solve(0, 0, vis, maze, ans, n);
    }
    return ans;
}