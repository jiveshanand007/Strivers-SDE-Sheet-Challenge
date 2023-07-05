#include <bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void generateLeft(TreeNode<int> *root, int lvl, vector<int> &ans)
{
    if (!root)
        return;
    if (lvl == ans.size())
        ans.push_back(root->data);
    generateLeft(root->left, lvl + 1, ans);
    generateLeft(root->right, lvl + 1, ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    generateLeft(root, 0, ans);
    return ans;
}