/************************************************************

   Following is the TreeNode class structure

   class TreeNode<T>
   {
   public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
   };


 ************************************************************/
#include <bits/stdc++.h>
void createMap(vector<int> &inorder, unordered_map<int, int> &m, int size)
{
    for (int i = 0; i < size; i++)
    {
        m[inorder[i]] = i;
    }
}
TreeNode<int> *solve(vector<int> &postorder, vector<int> &inorder,
                     int &idx, int start, int end, int n, unordered_map<int, int> &m)
{
    if (idx < 0 || start > end)
        return NULL;
    int ele = postorder[idx--];
    TreeNode<int> *root = new TreeNode<int>(ele);
    // int pos=findPos(inorder,ele,n);
    int pos = m[ele];
    root->right = solve(postorder, inorder, idx, pos + 1, end, n, m);
    root->left = solve(postorder, inorder, idx, start, pos - 1, n, m);
    return root;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postOrder, vector<int> &inOrder)
{
    int n = postOrder.size();

    int idx = n - 1;

    unordered_map<int, int> m;
    createMap(inOrder, m, n);

    TreeNode<int> *ans = solve(postOrder, inOrder, idx, 0, n - 1, n, m);
    return ans;
}
