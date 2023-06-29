#include <bits/stdc++.h>
// Stack class.
class Stack
{
private:
    int *arr;
    int peek;
    int size;

public:
    Stack(int capacity)
    {
        arr = new int[capacity];
        peek = -1;
        size = capacity;
    }

    void push(int num)
    {
        if (isFull())
            return;

        peek++;
        arr[peek] = num;
    }

    int pop()
    {
        if (peek >= 0)
        {
            int ans = arr[peek];
            peek--;
            return ans;
        }
        else
        {
            return -1;
        }
    }

    int top()
    {
        if (peek >= 0)
        {
            return arr[peek];
        }
        else
        {
            return -1;
        }
    }

    int isEmpty()
    {
        return (peek == -1) ? (1) : (0);
    }

    int isFull()
    {
        return size - peek == 1;
    }
};