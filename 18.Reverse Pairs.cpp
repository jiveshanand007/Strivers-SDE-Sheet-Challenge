#include <bits/stdc++.h>
int merge(vector<int> &nums, int low, int mid, int high)
{
    int cnt = 0;
    int j = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (j <= high && nums[i] > (long long)2 * nums[j])
        {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (nums[left] <= nums[right])
        {
            temp.push_back(nums[left++]);
        }
        else
            temp.push_back(nums[right++]);
    }
    while (left <= mid)
        temp.push_back(nums[left++]);
    while (right <= high)
        temp.push_back(nums[right++]);

    for (int i = low; i <= high; i++)
    {
        nums[i] = temp[i - low];
    }
    return cnt;
}
int mergeSort(vector<int> &nums, int low, int high)
{

    if (low >= high)
        return 0;
    int mid = (high + low) / 2;
    int nt = mergeSort(nums, low, mid);
    nt += mergeSort(nums, mid + 1, high);
    nt += merge(nums, low, mid, high);
    return nt;
}
int reversePairs(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, arr.size() - 1);
}