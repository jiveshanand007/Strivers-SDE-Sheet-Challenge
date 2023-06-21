string kthPermutation(int n, int k)
{
    vector<int> temp;
    string ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        temp.push_back(i);
    }
    temp.push_back(n);
    k -= 1;
    while (true)
    {
        ans += to_string(temp[k / fact]);
        temp.erase(temp.begin() + k / fact);
        if (temp.size() == 0)
            break;
        k %= fact;
        fact /= temp.size();
    }
    return ans;
}
