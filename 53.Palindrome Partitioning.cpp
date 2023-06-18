#include <bits/stdc++.h>
bool isPalindrome(string s, int l, int r)
{
    while (l <= r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

void findPalindrome(int idx, vector<string> &temp, string &s, vector<vector<string>> &ans)
{
    if (idx == s.size())
    {
        ans.push_back(temp);
    }

    for (int i = idx; i < s.size(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            temp.push_back(s.substr(idx, i - idx + 1)); 
            findPalindrome(i + 1, temp, s, ans);
            temp.pop_back();
        }
    }
}

vector<vector<string>> partition(string &s)
{
    vector<vector<string>> ans;
    vector<string> temp;
    findPalindrome(0, temp, s, ans);
    return ans;
}