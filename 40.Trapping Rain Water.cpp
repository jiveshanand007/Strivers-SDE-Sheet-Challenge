#include <bits/stdc++.h>
long getTrappedWater(long *arr, int n)
{
    long res = 0;
    long l = 0, r = n - 1;
    long lMax = 0, rMax = 0;
    while (l <= r)
    {
        if (arr[l] <= arr[r])
        {
            if (arr[l] >= lMax)
                lMax = arr[l];
            else
                res += lMax - arr[l];
            l++;
        }
        else
        {
            if (arr[r] >= rMax)
                rMax = arr[r];
            else
                res += rMax - arr[r];
            r--;
        }
    }
    return res;
}