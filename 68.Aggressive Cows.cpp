bool isPossible(int mid, vector<int> &stalls, int k)
{
    int n = stalls.size();
    int cnt = 1;
    int diff = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - diff >= mid)
        {
            cnt++;
            diff = stalls[i];
        }
    }
    if (cnt >= k)
        return true;
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());

    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) >> 1;

        if (isPossible(mid, stalls, k))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}