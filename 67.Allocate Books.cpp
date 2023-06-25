#include <bits/stdc++.h>
bool isPossible(long long barrier, vector<int> &time, long long n)
{
    int day = 1;
    long long tim = 0;
    for (auto it : time)
    {
        if (it + tim > barrier)
        {
            day++;
            tim = it;
            if (it > barrier || day > n)
                return false;
        }
        else
        {
            tim += it;
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time)
{
    long long ans = 0;
    long long low = time[0];
    long long high = 0;
    for (long long it : time)
    {
        high += it;
        low = min(low, it);
    }

    while (low <= high)
    {
        long long mid = (low + high) >> 1;
        if (isPossible(mid, time, n))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}