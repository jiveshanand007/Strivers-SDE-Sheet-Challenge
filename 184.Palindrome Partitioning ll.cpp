#include <bits/stdc++.h>
bool isPalindrome(int i, int j, string s)
{
    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}
// int countPartition(int i,string &str,vector<int> &dp,int n){
//     if(i == n) return 0;
//     if(dp[i] != -1) return dp[i];
//     int ans = INT_MAX;
//     for(int j=i;j<n;j++){
//         if(isPalindrome(i,j,str)){
//             int temp = 1 + countPartition(j+1,str,dp,n);
//             ans = min(ans,temp);
//         }
//     }
//     return dp[i] = ans;
// }
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n + 1, 0);
    // return countPartition(0, str, dp, n)-1;

    for (int i = n - 1; i >= 0; i--)
    {
        int ans = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, str))
            {
                int temp = 1 + dp[j + 1];
                ans = min(ans, temp);
            }
        }
        dp[i] = ans;
    }
    return dp[0] - 1;
}
