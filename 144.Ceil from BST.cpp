#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void findCeil(BinaryTreeNode<int> *root, int x, int &ans)
{
    if (!root)
        return;

    if (root->data == x)
    {
        ans = root->data;
        return;
    }
    if (root->data > x)
    {
        ans = root->data;
        findCeil(root->left, x, ans);
    }
    else
    {
        findFloor(root->right, x, ans);
    }
}
int findCeil(BinaryTreeNode<int> *node, int x)
{
    int ans = INT_MIN;
    findFloor(node, x, ans);
    return ans == INT_MIN ? -1 : ans;
}