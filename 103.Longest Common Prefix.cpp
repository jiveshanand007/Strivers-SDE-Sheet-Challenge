#include <algorithm>
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";
    sort(arr.begin(), arr.end());

    string first = arr[0], last = arr[n - 1];

    for (int i = 0; i < min(first.length(), last.length()); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}
