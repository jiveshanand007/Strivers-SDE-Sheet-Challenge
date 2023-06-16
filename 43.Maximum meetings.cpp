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
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<pair<int, int>, int>> m;
    for (int i = 0; i < n; i++)
    {
        m.push_back({{end[i], start[i]}, i + 1});
    }
    sort(m.begin(), m.end(), comparator);
    int lastMeetEnd = m[0].first.first;
    int totalMeet = 1;
    vector<int> ans;
    ans.push_back(m[0].second);
    for (int i = 1; i < n; i++)
    {
        if (m[i].first.second > lastMeetEnd)
        {
            lastMeetEnd = m[i].first.first;
            ans.push_back(m[i].second);
            totalMeet++;
        }
    }
    return ans;
}