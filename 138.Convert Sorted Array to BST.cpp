#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

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
TreeNode<int> *generateBST(int start, int end, vector<int> &arr)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = generateBST(start, mid - 1, arr);
    root->right = generateBST(mid + 1, end, arr);
    return root;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    int start = 0, end = arr.size() - 1;
    return generateBST(start, end, arr);
}