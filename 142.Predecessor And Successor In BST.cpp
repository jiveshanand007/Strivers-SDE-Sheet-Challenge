#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/
void findpresuc(BinaryTreeNode<int> *root, int key, pair<int, int> &ans)
{
    if (!root)
        return;
    if (root->data == key)
    {
        if (root->left)
        {
            BinaryTreeNode<int> *temp = root->left;
            while (temp->right)
                temp = temp->right;
            ans.first = temp->data;
        }
        if (root->right)
        {
            BinaryTreeNode<int> *temp = root->right;
            while (temp->left)
                temp = temp->left;
            ans.second = temp->data;
        }
        return;
    }

    if (root->data > key)
    {
        ans.second = root->data;
        findpresuc(root->left, key, ans);
    }
    else
    {
        ans.first = root->data;
        findpresuc(root->right, key, ans);
    }
}
pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    pair<int, int> ans = {-1, -1};

    findpresuc(root, key, ans);
    return ans;
}
