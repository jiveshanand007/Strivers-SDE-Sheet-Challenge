#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure.

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    vector<int> ans;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    map<int, int> mp;

    q.push({root, 0});

    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        BinaryTreeNode<int> *node = curr.first;
        int lvl = curr.second;

        mp[lvl] = node->data;
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
