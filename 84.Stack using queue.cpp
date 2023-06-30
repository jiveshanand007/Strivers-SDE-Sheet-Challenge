#include <bits/stdc++.h>
class Stack
{
    // Define the data members.
    queue<int> q;
    int sz;

public:
    Stack()
    {
        // Implement the Constructor.
        sz = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return sz;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return sz == 0;
    }

    void push(int element)
    {
        // Implement the push() function.

        q.push(element);

        for (int i = 0; i < sz; i++)
        {
            q.push(q.front());
            q.pop();
        }
        sz++;
    }

    int pop()
    {
        // Implement the pop() function.
        if (!q.empty())
        {
            int ans = q.front();

            q.pop();
            sz--;

            return ans;
        }
        return -1;
    }

    int top()
    {
        // Implement the top() function.
        if (!q.empty())
            return q.front();
        return -1;
    }
};