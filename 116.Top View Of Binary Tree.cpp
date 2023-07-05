#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        TreeNode<int> *node = curr.first;
        int lvl = curr.second;

        if (mp.find(lvl) == mp.end())
            mp[lvl] = node->val;
        if (node->left)
        {
            q.push({node->left, lvl - 1});
        }
        if (node->right)
        {
            q.push({node->right, lvl + 1});
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}