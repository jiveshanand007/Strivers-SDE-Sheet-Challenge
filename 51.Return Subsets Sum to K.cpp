#include <bits/stdc++.h>
void solve(int ind, int k, int sum, vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans)
{
    if (ind == arr.size())
    {
        if (sum == k)
        {
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[ind]);
    solve(ind + 1, k, sum + arr[ind], arr, temp, ans);
    temp.pop_back();

    solve(ind + 1, k, sum, arr, temp, ans);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> temp;
    solve(0, k, 0, arr, temp, ans);
    return ans;
}