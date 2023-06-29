#include <bits/stdc++.h>
class three
{
public:
    int data, idx, jdx;
};
struct comparator
{
    bool operator()(three a, three b)
    {
        return a.data > b.data;
    }
};
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<three, vector<three>, comparator> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push({kArrays[i][0], i, 0});
    }
    vector<int> ans;
    while (!pq.empty())
    {
        three obj = pq.top();
        pq.pop();
        int val = obj.data, i = obj.idx, j = obj.jdx;

        ans.push_back(val);
        if (j + 1 < kArrays[i].size())
        {
            pq.push({kArrays[i][j + 1], i, j + 1});
        }
    }

    return ans;
}
