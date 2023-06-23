int cntSmallerthanEqualtoMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;

    while (l <= h)
    {
        int md = (l + h) / 2;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
            h = md - 1;
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 1;
    int high = 1e9 + 7;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += cntSmallerthanEqualtoMid(matrix[i], mid);
        }
        if (cnt <= (m * n) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}