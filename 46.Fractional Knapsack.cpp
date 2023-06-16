#include <bits/stdc++.h>
bool compare(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    sort(items.begin(), items.end(), compare);
    double currW = 0;
    double totalV = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (currW + items[i].first <= w)
        {
            currW += items[i].first;
            totalV += items[i].second;
        }
        else
        {
            double remain = w - currW;
            totalV += (double)((double)items[i].second / (double)items[i].first) * (double)remain;
            break;
        }
    }
    return totalV;
}