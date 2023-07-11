#include <bits/stdc++.h>
/*
    template <typename T = int>
    class TreeNode
    {
        public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if (left != NULL)
            {
                delete left;
            }
            if (right != NULL)
            {
                delete right;
            }
        }
    };
*/

bool findPath(TreeNode<int> *root, int x, vector<int> &arr)
{
    if (!root)
        return false;
    arr.push_back(root->data);

    if (root->data == x)
        return true;
    if (findPath(root->left, x, arr) || findPath(root->right, x, arr))
        return true;

    arr.pop_back();
    return false;
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    vector<int> ans;
    bool flag = findPath(root, x, ans);
    return ans;
}
