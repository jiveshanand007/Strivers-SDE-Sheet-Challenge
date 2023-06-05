#include <bits/stdc++.h>
vector<int> nextPermutation(vector<int> &permutation, int n)
{

    int idx = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (permutation[i] < permutation[i + 1])
        {
            idx = i;
            break;
        }
    }
    if (idx != -1)
        for (int i = n - 1; i >= 0; i--)
        {
            if (permutation[idx] < permutation[i])
            {
                swap(permutation[idx], permutation[i]);
                break;
            }
        }
    reverse(permutation.begin() + idx + 1, permutation.end());
    return permutation;
}