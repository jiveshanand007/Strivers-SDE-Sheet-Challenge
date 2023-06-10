#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n)
{
    unordered_set<int> set;
    for (int i : nums)
    {
        set.insert(i);
    }
    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        if (set.find(nums[i] - 1) == set.end())
        {
            int currNum = nums[i];
            int currLen = 1;

            while (set.find(currNum + 1) != set.end())
            {
                currLen++;
                currNum++;
            }
            maxLen = max(currLen, maxLen);
        }
    }
    return maxLen;
}