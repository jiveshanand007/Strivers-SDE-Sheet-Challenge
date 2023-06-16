#include <bits/stdc++.h>
bool compare(vector<int> v1, vector<int> v2)
{
    if (v1[1] > v2[1])
        return true;
    return false;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    int sum = 0;
    sort(jobs.begin(), jobs.end(), compare);
    int time = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        time = max(time, jobs[i][0]);
    }
    vector<int> temp(time + 1, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (temp[j] == -1)
            {
                temp[j] = i;
                cnt++;
                sum += jobs[i][1];
                break;
            }
        }
    }
    return sum;
}
