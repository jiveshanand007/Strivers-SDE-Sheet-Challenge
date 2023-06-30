#include <bits/stdc++.h>
int findMin(stack<int> s)
{
    if (s.size() == 1)
        return s.top();

    int temp = s.top();
    s.pop();
    int mini = findMin(s);
    if (temp < mini)
        mini = temp;
    return mini;
}
void pushIntoStack(int num, stack<int> &s)
{
    if (s.empty() || s.top() < num)
    {
        s.push(num);
        return;
    }

    int temp = s.top();
    s.pop();
    pushIntoStack(num, s);
    s.push(temp);
    return;
}
void sortStack(stack<int> &stack)
{
    if (stack.size() == 0 || stack.size() == 1)
        return;
    int temp = stack.top();
    stack.pop();
    sortStack(stack);
    pushIntoStack(temp, stack);
    return;
}