#include <bits/stdc++.h>
bool findHalfSum(int i, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (i == 0)
    {
        return arr[0] == target;
    }

    if (dp[i][target] != -1)
        return dp[i][target];
    int notTake = findHalfSum(i - 1, target, arr, dp);
    int take = false;
    if (arr[i] <= target)
    {
        take = findHalfSum(i - 1, target - arr[i], arr, dp);
    }
    return dp[i][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    int sum = accumulate(arr.begin(), arr.end(), 0);
    // if(sum%2!=0) return false;
    int target = sum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return findHalfSum(n - 1, k, arr, dp);
}