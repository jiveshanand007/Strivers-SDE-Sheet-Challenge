#include <bits/stdc++.h>
class Queue
{
    stack<int> input, output;

public:
    Queue()
    {
        // Initialize your data structure here.
    }

    void enQueue(int val)
    {
        input.push(val);
    }

    int deQueue()
    {
        if (isEmpty())
            return -1;
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();

        int x = output.top();
        output.pop();
        return x;
    }

    int peek()
    {
        if (isEmpty())
            return -1;
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    bool isEmpty()
    {
        return input.size() + output.size() == 0;
    }
};