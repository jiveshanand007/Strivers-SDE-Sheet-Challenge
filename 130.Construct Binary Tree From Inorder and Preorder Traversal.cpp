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
void createMapping(vector<int> &inorder, unordered_map<int, int> &mp)
{
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
}
TreeNode<int> *createTree(int &idx, int inorderStart, int inorderEnd, vector<int> &inorder,
                          vector<int> &preorder, unordered_map<int, int> &mp)
{
    if (idx >= inorder.size() || inorderStart > inorderEnd)
        return NULL;

    int ele = preorder[idx++];
    TreeNode<int> *root = new TreeNode<int>(ele);
    int pos = mp[ele];
    root->left = createTree(idx, inorderStart, pos - 1, inorder, preorder, mp);
    root->right = createTree(idx, pos + 1, inorderEnd, inorder, preorder, mp);
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    unordered_map<int, int> mp;
    createMapping(inorder, mp);
    int preIdx = 0;
    return createTree(preIdx, 0, inorder.size() - 1, inorder, preorder, mp);
}