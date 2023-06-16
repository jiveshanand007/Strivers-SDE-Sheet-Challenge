int calculateMinPatforms(int at[], int dt[], int n)
{
    sort(at, at + n);
    sort(dt, dt + n);
    int i = 0, j = 1;
    int cnt = 1;
    int ans = 1;
    while (i < n && j < n)
    {
        if (at[j] <= dt[i])
        {
            cnt++;
            j++;
        }
        else
        {
            cnt--;
            i++;
        }
        ans = max(ans, cnt);
    }
    return ans;
}