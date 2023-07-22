
#include <bits/stdc++.h>

int findMaxSum(int i, int j, int arr[], int n, vector<vector<int>> &dp)
{
    if (i == n)
        return 0;

    if (dp[i][j + 1] != -1)
        return dp[i][j + 1];
    int notTake = findMaxSum(i + 1, j, arr, n, dp);
    int take = 0;
    if (j == -1 || arr[i] > arr[j])
    {
        take = arr[i] + findMaxSum(i + 1, i, arr, n, dp);
    }
    return dp[i][j + 1] = max(take, notTake);
}
int maxIncreasingDumbbellsSum(vector<int> &arr, int n)
{

    // vector<vector<int>> dp(n,vector<int>(n+1,-1));
    // return findMaxSum(0,-1,arr,n,dp);
    vector<int> ahead(n + 1, 0), curr(n + 1, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int notTake = ahead[j + 1];
            int take = 0;
            if (j == -1 || arr[i] > arr[j])
            {
                take = arr[i] + ahead[i + 1];
            }
            curr[j + 1] = max(take, notTake);
        }
        ahead = curr;
    }
    return ahead[0];
}