#include <bits/stdc++.h>
int findMinimumCoins(int amount)
{
    int coins[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int currAm = 0;
    int cnt = 0;
    for (int i = 0; i < 9; i++)
    {
        while (amount >= coins[i])
        {
            amount -= coins[i];
            cnt++;
        }
    }
    return cnt;
}
