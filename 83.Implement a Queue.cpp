#include <bits/stdc++.h>
class Queue
{
private:
    int *arr;
    int frnt;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        frnt = 0;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        if (frnt == rear)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        if (rear != size)
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
        if (frnt == rear)
            return -1;
        else
        {
            int ans = arr[frnt];
            arr[frnt] = -1;
            frnt++;
            if (frnt == rear)
            {
                frnt = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front()
    {
        if (frnt == rear)
            return -1;
        return arr[frnt];
    }
};