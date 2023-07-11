#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void printLeft(TreeNode<int> *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        printLeft(root->left, ans);
    }
    else
    {
        printLeft(root->right, ans);
    }
}
void printLeaf(TreeNode<int> *root, vector<int> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        ans.push_back(root->data);
        return;
    }
    printLeaf(root->left, ans);
    printLeaf(root->right, ans);
}
void printRight(TreeNode<int> *root, vector<int> &ans)
{
    if (!root || (!root->left && !root->right))
    {
        return;
    }
    if (root->right)
    {
        printRight(root->right, ans);
    }
    else
    {
        printRight(root->left, ans);
    }

    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{

    vector<int> ans;

    ans.push_back(root->data);
    printLeft(root->left, ans);

    printLeaf(root->left, ans);
    printLeaf(root->right, ans);

    printRight(root->right, ans);

    return ans;
}