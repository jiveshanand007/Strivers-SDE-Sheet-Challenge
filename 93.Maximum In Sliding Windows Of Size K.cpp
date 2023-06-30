#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        // removing out of bounds
        if (!dq.empty() && (i - k == dq.front()))
            dq.pop_front();

        // removing num <arr[i];
        while (!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(nums[dq.front()]);
    }
    return ans;
}