int longestSubSeg(vector<int> &arr, int n, int k)
{
    int cnt = 0;
    int cntMax = 0;

    for (int j = 0, i = 0; j < n; j++)
    {
        if (arr[j] == 0)
            cnt++;

        while (cnt > k)
        {
            if (arr[i] == 0)
            {
                cnt--;
            }
            i++;
        }
        cntMax = max(cntMax, j - i + 1);
    }
    return cntMax;
}
