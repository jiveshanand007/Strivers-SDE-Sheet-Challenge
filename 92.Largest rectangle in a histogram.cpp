// Optimised 1 (accepted 50%)
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> leftSmaller(n, 0), rightSmaller(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (s.empty())
                leftSmaller[i] = 0;
            else
                leftSmaller[i] = s.top() + 1;
            s.push(i);
        }
        while (!s.empty())
            s.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() && heights[s.top()] >= heights[i])
                s.pop();
            if (s.empty())
                rightSmaller[i] = n - 1;
            else
                rightSmaller[i] = s.top() - 1;
            s.push(i);
        }
        int maxArea = 0;
        for (int i = 0; i < n; i++)
        {
            maxArea = max(maxArea, (rightSmaller[i] - leftSmaller[i] + 1) * heights[i]);
        }
        return maxArea;
    }
};

// Optimised 2 (better)
#include <bits/stdc++.h>
int largestRectangle(vector<int> &heights)
{
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!s.empty() && (i == n || heights[s.top()] >= heights[i]))
        {
            int height = heights[s.top()];
            s.pop();
            int width;
            if (s.empty())
                width = i;
            else
                width = i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}