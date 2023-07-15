#include <bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure

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

int KthLargestNumber(TreeNode<int> *root, int k)
{
    TreeNode<int> *curr = root;
    int ans = -1;

    while (curr)
    {
        if (curr->right)
        {
            TreeNode<int> *pred = curr->right;
            while (pred->left && pred->left != curr)
                pred = pred->left;

            if (!pred->left)
            {
                pred->left = curr;
                curr = curr->right;
            }
            else
            {
                pred->left = NULL;

                k--;
                if (k == 0)
                {
                    ans = curr->data;
                }

                curr = curr->left;
            }
        }
        else
        {
            k--;
            if (k == 0)
            {
                ans = curr->data;
            }
            curr = curr->left;
        }
    }
    return ans;
}
