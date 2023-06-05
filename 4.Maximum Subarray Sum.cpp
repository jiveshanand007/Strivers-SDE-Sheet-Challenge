#include <bits/stdc++.h>
long long maxSubarraySum(int arr[], int n)
{
    long long curr = 0, maxSum = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        curr = curr + arr[i];
        if (curr < 0)
            curr = 0;
        maxSum = max(curr, maxSum);
    }
    return maxSum;
}