#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/

vector<int> inorder;

vector<int> preorder;

vector<int> postorder;

void solve(BinaryTreeNode<int> *root)

{

    if (!root)
        return;

    preorder.push_back(root->data);

    solve(root->left);

    inorder.push_back(root->data);

    solve(root->right);

    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{

    // Write your code here.

    vector<vector<int>> ans;

    solve(root);

    ans.push_back(inorder);

    ans.push_back(preorder);

    ans.push_back(postorder);

    inorder.clear();

    preorder.clear();

    postorder.clear();

    return ans;
}