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
pair<bool, int> ifbalanced(BinaryTreeNode<int> *root)
{
    if (!root)
        return {true, 0};

    pair<bool, int> left = ifbalanced(root->left);
    pair<bool, int> right = ifbalanced(root->right);
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    if (left.first && right.first && diff)
        ans.first = true;
    else
        ans.first = false;
    ans.second = max(left.second, right.second) + 1;
    return ans;
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    return ifbalanced(root).first;
}