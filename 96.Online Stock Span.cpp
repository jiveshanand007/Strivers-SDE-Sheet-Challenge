#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price)
{
    int n = price.size();
    vector<int> ans(n);
    stack<pair<int, int>> st;

    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (!st.empty() && st.top().first <= price[i])
        {
            cnt += st.top().second;
            st.pop();
        }
        ans[i] = cnt;
        st.push({price[i], cnt});
    }
    return ans;
}