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
bool isTrue(BinaryTreeNode<int> *root, int mini, int maxi)
{
    if (!root)
        return true;
    if (root->data >= mini && root->data <= maxi)
    {
        bool left = isTrue(root->left, mini, root->data);
        bool right = isTrue(root->right, root->data, maxi);
        return left && right;
    }
    return false;
}
bool validateBST(BinaryTreeNode<int> *root)
{
    return isTrue(root, INT_MIN, INT_MAX);
}