#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    if (n == 1)
        return intervals;
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int ptr1 = intervals[0][0];
    int ptr2 = intervals[0][1];
    int i = 1;
    while (i <= n - 1)
    {
        if (intervals[i][0] <= ptr2)
        {
            ptr2 = max(ptr2, intervals[i][1]);
        }
        else
        {
            ans.push_back({ptr1, ptr2});
            ptr1 = intervals[i][0];
            ptr2 = intervals[i][1];
        }
        i++;
    }
    ans.push_back({ptr1, ptr2});
    return ans;
}
