#include <bits/stdc++.h>
long long getInversions(long long *arr, int n)
{
    long long ans = 0;
    int i = 0, j = 1;
    while (i < n - 1)
    {
        if (arr[i] > arr[j])
        {
            ans++;
        }
        j++;
        if (j >= n)
        {
            i++;
            j = i + 1;
        }
    }
    return ans;
}