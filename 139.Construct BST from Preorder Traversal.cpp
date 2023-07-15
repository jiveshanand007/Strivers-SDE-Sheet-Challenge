#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> *generateTree(vector<int> &arr, int &i, int mini, int maxi)
{
    if (i >= arr.size())
        return NULL;
    if (arr[i] > maxi || arr[i] < mini)
        return NULL;
    int val = arr[i++];
    TreeNode<int> *root = new TreeNode<int>(val);
    root->left = generateTree(arr, i, mini, val);
    root->right = generateTree(arr, i, val, maxi);
    return root;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    int i = 0;
    return generateTree(preOrder, i, INT_MIN, INT_MAX);
}