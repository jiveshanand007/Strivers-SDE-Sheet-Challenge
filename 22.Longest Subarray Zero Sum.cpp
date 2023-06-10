#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{
    int n = arr.size();
    int sum = 0;
    int maxLen = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else
        {
            if (mp.find(sum) != mp.end())
            {
                maxLen = max(maxLen, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
    }
    return maxLen;
}