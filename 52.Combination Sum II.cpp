#include <bits/stdc++.h>>
void solve(int i, int target, vector<int> &c, vector<int> &temp, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(temp);
        return;
    }
    for (int idx = i; idx < c.size(); idx++)
    {
        if (idx > i && c[idx] == c[idx - 1])
            continue;
        if (c[idx] > target)
            break;
        temp.push_back(c[idx]);
        solve(idx + 1, target - c[idx], c, temp, ans);
        temp.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, target, arr, temp, ans);
    return ans;
}
