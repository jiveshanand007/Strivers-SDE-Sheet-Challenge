#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

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

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    vector<int> res;
    if (!root)
        return res;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool flag = true;

    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp(sz);

        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            int idx = flag ? i : sz - i - 1;
            temp[idx] = node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        flag = !flag;
        for (auto it : temp)
            res.push_back(it);
    }
    return res;
}
