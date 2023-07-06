#include <bits/stdc++.h>

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    map<int, vector<int>> nodes;
    queue<pair<TreeNode<int> *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(0, 0)));
    while (!q.empty())
    {
        pair<TreeNode<int> *, pair<int, int>> temp = q.front();
        TreeNode<int> *frontnode = temp.first;
        q.pop();
        int row = temp.second.first;
        int col = temp.second.second;
        nodes[row].push_back(frontnode->data);
        if (frontnode->left)
            q.push(make_pair(frontnode->left, make_pair(row - 1, col - 1)));
        if (frontnode->right)
            q.push(make_pair(frontnode->right, make_pair(row + 1, col - 1)));
    }
    for (auto i : nodes)
    {
        // vector<int> a;
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
        // ans.push_back(a);
    }
    return ans;
}