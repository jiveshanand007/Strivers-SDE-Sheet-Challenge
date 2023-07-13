#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool findPath(TreeNode<int> *root, stack<TreeNode<int> *> &path,
              TreeNode<int> *&leaf)
{
    path.push(root);
    if (!root->left && !root->right)
    {
        if (root->data == leaf->data)
            return true;

        else
        {
            path.pop();
            return false;
        }
    }
    if (root->left)
    {
        if (findPath(root->left, path, leaf))
            return true;
    }
    if (root->right)
    {
        if (findPath(root->right, path, leaf))
            return true;
    }
    path.pop();
    return false;
}
TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
    stack<TreeNode<int> *> q;
    findPath(root, q, leaf);
    // cout<<"__"<<q.size()<<"__";
    TreeNode<int> *newRoot = q.top();
    q.pop();
    TreeNode<int> *parent = newRoot;
    while (!q.empty())
    {
        // cout<<"*"<<q.top()->data<<"*";
        // q.pop();

        TreeNode<int> *curr = q.top();
        q.pop();

        if (curr->left == parent)
        {
            curr->left = NULL;
            parent->left = curr;
        }
        else
        {
            curr->right = curr->left;
            curr->left = NULL;
            parent->left = curr;
        }
        parent = parent->left;
    }
    return newRoot;
}
