#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0;
    int candidate1 = INT_MIN, candidate2 = INT_MIN;
    for (auto it : arr)
    {
        if (cnt1 == 0 && it != candidate2)
            candidate1 = it;
        else if (cnt2 == 0 && it != candidate1)
            candidate2 = it;
        if (it == candidate1)
            cnt1++;
        else if (it == candidate2)
            cnt2++;
        else
            cnt1--, cnt2--;
    }
    cnt1 = 0, cnt2 = 0;
    for (auto it : arr)
    {
        if (it == candidate1)
            cnt1++;
        else if (it == candidate2)
            cnt2++;
    }
    if (cnt1 > n / 3)
        ans.push_back(candidate1);
    if (cnt2 > n / 3)
        ans.push_back(candidate2);
    return ans;
}