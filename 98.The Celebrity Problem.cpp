#include <bits/stdc++.h>
/*
    This is signature of helper function 'knows'.
    You should not implement it, or speculate about its implementation.

    bool knows(int A, int B);
    Function 'knows(A, B)' will returns "true" if the person having
    id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n)
{
    // Write your code here.
    stack<int> s;
    for (int i = 0; i < n; i++)
        s.push(i);

    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(a, b))
            s.push(b);
        else
            s.push(a);
    }
    int potentialCeleb = s.top();
    int cntZero = 0;
    for (int i = 0; i < n; i++)
    {
        if (potentialCeleb != i && (knows(potentialCeleb, i) || !knows(i, potentialCeleb)))
            return -1;
    }
    return potentialCeleb;
}