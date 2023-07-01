// T.C O(n)
// S.C O(2n)

// Approach 1
class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack()
    {
        while (!st.empty())
            st.pop();
    }

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            if (val < st.top().first)
                st.push({val, val});
            else
                st.push({st.top().first, val});
        }
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
        return;
    }

    int top()
    {
        return st.top().second;
    }

    int getMin()
    {
        return st.top().first;
    }
};

// SC O(n)

// Approach 2
#include <bits/stdc++.h>
// Implement class for minStack.
class minStack
{
    // Write your code here.
    stack<long long> s;
    int mini = INT_MAX;

public:
    // Constructor
    minStack()
    {
        while (!s.empty())
            s.pop();
    }

    // Function to add another element equal to num at the top of stack.
    void push(int num)
    {
        long long val = num;
        if (s.empty())
        {
            mini = val;
            s.push(val);
        }
        else
        {
            if (val < mini)
            {
                s.push(2 * val * 1LL - mini);
                mini = val;
            }
            else
            {
                s.push(val);
            }
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        // Write your code here.
        if (s.empty())
            return -1;
        long long ele = s.top();
        s.pop();

        if (ele < mini)
        {
            int x = mini;
            mini = 2 * mini - ele;
            return x;
        }

        return ele;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        // Write your code here.
        if (s.empty())
            return -1;
        if (s.top() < mini)
            return mini;
        return s.top();
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        // Write your code here.
        if (s.empty())
            return -1;
        return mini;
    }
};