#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    int cnt = 0;
    int candidate;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
            candidate = arr[i];
        if (candidate == arr[i])
            cnt++;
        else
            cnt--;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == candidate)
            cnt1++;
    }
    return cnt1 > n / 2 ? candidate : -1;
}