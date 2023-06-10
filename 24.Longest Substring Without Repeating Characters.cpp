#include <bits/stdc++.h>
int uniqueSubstrings(string s)
{
    int n = s.size();
    unordered_set<int> st;
    int maxLen = 0;
    int left = 0;
    for (int right = 0; right < n; right++)
    {

        if (st.find(s[right]) != st.end())
        {
            while (left < right && st.find(s[right]) != st.end())
            {
                st.erase(s[left]);
                left++;
            }
        }
        st.insert(s[right]);
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}