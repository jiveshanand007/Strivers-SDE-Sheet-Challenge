#include <bits/stdc++.h>
bool areAnagram(string &str1, string &str2)
{
    unordered_map<char, int> count;

    // Count the frequency of characters in string s
    for (auto x : str1)
    {
        count[x]++;
    }

    // Decrement the frequency of characters in string t
    for (auto x : str2)
    {
        count[x]--;
    }

    // Check if any character has non-zero frequency
    for (auto x : count)
    {
        if (x.second != 0)
        {
            return false;
        }
    }

    return true;
}