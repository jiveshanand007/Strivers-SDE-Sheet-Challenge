vector<int> zAlgo(string input)
{
    int n = input.length();
    vector<int> zArray(n);

    int left = 0, right = 0;
    for (int k = 1; k < n; k++)
    {
        if (k > right)
        {
            left = right = k;
            while (right < n && input[right] == input[right - left])
            {
                right++;
            }
            zArray[k] = right - left;
            right--;
        }
        else
        {
            int k1 = k - left;

            if (zArray[k1] < right - k + 1)
            {
                zArray[k] = zArray[k1];
            }
            else
            {
                left = k;
                while (right < n && input[right] == input[right - left])
                {
                    right++;
                }
                zArray[k] = right - left;
                right--;
            }
        }
    }
    return zArray;
}
int zAlgorithm(string s, string p, int n, int m)
{
    if (s == p)
        return 1;
    if (m > n)
        return 0;
    string temp = p;
    temp += "#";
    temp += s;
    vector<int> zArray = zAlgo(temp);
    int cnt = 0;
    for (int i = 0; i < zArray.size(); i++)
    {
        if (zArray[i] == m)
        {
            cnt++;
        }
    }
    return cnt;
}