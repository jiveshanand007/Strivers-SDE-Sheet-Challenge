string reverseString(string &str)
{
    string ans = "";
    string temp = "";
    int n = str.length();
    int l = 0, r = n - 1;

    while (str[l] == ' ')
        l++;
    while (str[r] == ' ')
        r--;

    while (l <= r)
    {
        if (str[l] != ' ')
            temp += str[l];
        else
        {
            if (str[l - 1] == ' ')
            {
                l++;
                continue;
            }
            if (ans != "")
                ans = temp + " " + ans;
            else
                ans = temp;
            temp = "";
        }
        l++;
    }
    if (temp != "")
    {
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }
    return ans;
}