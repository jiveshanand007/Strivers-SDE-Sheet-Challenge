#include <bits/stdc++.h>
void heapify(vector<int> &arr, int n, int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[smallest] > arr[left])
    {
        smallest = left;
    }
    if (right < n && arr[smallest] > arr[right])
    {
        smallest = right;
    }
    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
    return;
}
vector<int> minHeap(int n, vector<vector<int>> &q)
{
    vector<int> minheap;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (q[i][0] == 0)
        {
            minheap.push_back(q[i][1]);
            int size = minheap.size();
            for (int j = size / 2 - 1; j >= 0; j--)
            {
                heapify(minheap, size, j);
            }
        }
        else
        {
            int size = minheap.size();
            int era = minheap[0];
            swap(minheap[0], minheap[size - 1]);
            minheap.pop_back();
            size--;

            heapify(minheap, size, 0);
            ans.push_back(era);
        }
    }
    return ans;
}
