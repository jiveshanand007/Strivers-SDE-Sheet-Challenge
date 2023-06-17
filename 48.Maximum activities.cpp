#include <bits/stdc++.h>
bool comparator(pair<pair<int, int>, int> m1,
                pair<pair<int, int>, int> m2)
{
    if (m1.first.first < m2.first.first)
        return true;
    else if (m1.first.first > m2.first.first)
        return false;
    else if (m1.second < m2.second)
        return true;
    return false;
}
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    vector<pair<pair<int, int>, int>> ac;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        ac.push_back({{finish[i], start[i]}, i + 1});
    }
    sort(ac.begin(), ac.end(), comparator);
    int endTask = ac[0].first.first;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (ac[i].first.second >= endTask)
        {
            endTask = ac[i].first.first;
            cnt++;
        }
    }
    return cnt;
}