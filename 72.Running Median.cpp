#include <bits/stdc++.h>
void findMedian(int *arr, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int j = 0; j < n; j++)
    {
        if (maxHeap.empty() || maxHeap.top() > arr[j])
        {
            maxHeap.push(arr[j]);
        }
        else
        {
            minHeap.push(arr[j]);
        }
        if (maxHeap.size() > minHeap.size())
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        if (minHeap.size() < maxHeap.size())
            cout << maxHeap.top() << " ";
        else
            cout << (minHeap.top() + maxHeap.top()) / 2 << " ";
    }
}