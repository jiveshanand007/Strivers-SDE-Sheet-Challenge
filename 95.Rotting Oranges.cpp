#include <bits/stdc++.h>

int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int cntF = 0, cntR = 0, time = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                vis[i][j] = 2;
            }
            if (grid[i][j] == 1)
                cntF++;
        }
    }

    int dr[4] = {0, 1, 0, -1};
    int dc[4] = {1, 0, -1, 0};
    while (!q.empty())
    {
        int t = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        time = max(t, time);

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 2 && grid[nr][nc] == 1)
            {
                vis[nr][nc] = 2;
                q.push({t + 1, {nr, nc}});
                cntR++;
            }
        }
    }
    if (cntR != cntF)
        return -1;
    return time;
}