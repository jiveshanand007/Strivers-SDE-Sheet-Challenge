#include <vector>
#include <algorithm>
vector<int> kmpAlgo(string input, int m)
{
    vector<int> lps(m);
    lps[0] = 0;

    for (int i = 1; i < m; i++)
    {
        int j = lps[i - 1];
        while (j > 0 && input[i] != input[j])
        {
            j = lps[j - 1];
        }
        if (input[i] == input[j])
        {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

int minCharsforPalindrome(string str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    temp = str + "#" + temp;
    int n = temp.length();
    vector<int> pi = kmpAlgo(temp, n);

    return str.length() - pi[n - 1];
}
