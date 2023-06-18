#include <bits/stdc++.h>
void getPermutation(int idx, string nums, vector<string> &ans)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
    }
    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[i], nums[idx]);
        getPermutation(idx + 1, nums, ans);
        swap(nums[i], nums[idx]);
    }
}
vector<string> findPermutations(string &s)
{
    vector<string> ans;
    getPermutation(0, s, ans);
    return ans;
}