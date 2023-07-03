vector<int> stringMatch(string text, string pattern)
{
    int m = pattern.size(), n = text.size();
    if (m > n)
        return {0};
    if (text == pattern)
        return {1};
    vector<int> ans;
    int base = 1000000;

    int power = 1;
    for (int i = 0; i < m; i++)
        power = (power * 29) % base;

    int patternHash = 0;
    for (int i = 0; i < m; i++)
        patternHash = (patternHash * 29 + pattern[i]) % base;

    int textHash = 0;
    for (int i = 0; i < n; i++)
    {
        textHash = (textHash * 29 + text[i]) % base;
        if (i < m - 1)
            continue;
        if (i >= m)
        {
            textHash = (textHash - text[i - m] * power) % base;
        }
        if (textHash < 0)
            textHash += base;
        if (textHash == patternHash)
        {
            if (text.substr(i - m + 1, m) == pattern)
            {
                ans.push_back(i - m + 2);
            }
        }
    }

    return ans;
}
