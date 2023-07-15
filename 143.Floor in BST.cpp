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
void findFloor(TreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;

    if (root->val == x)
    {
        ans = root->val;
        return;
    }
    if (root->val < x)
    {
        ans = root->val;
        findFloor(root->right, x, ans);
    }
    else
    {
        findFloor(root->left, x, ans);
    }
}
int floorInBST(TreeNode<int> *root, int X)
{
    int ans = INT_MAX;
    findFloor(root, X, ans);
    return ans;
}