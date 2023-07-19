#include <bits/stdc++.h>
int maximumProduct(vector<int> &arr, int n)
{
    if (n == 1)
        return arr[0];
    int ans = arr[0];
    int mini, maxi;
    maxi = mini = ans;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxi, mini);

        maxi = max(arr[i], arr[i] * maxi);
        mini = min(arr[i], arr[i] * mini);
        ans = max(ans, maxi);
    }
    return ans;
}
