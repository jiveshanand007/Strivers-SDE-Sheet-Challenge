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

int kthSmallest(TreeNode<int> *root, int k)
{
    TreeNode<int> *curr = root;
    int ans = 0;

    while (curr)
    {
        if (curr->left)
        {
            TreeNode<int> *pred = curr->left;
            while (pred->right && pred->right != curr)
                pred = pred->right;

            if (!pred->right)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                pred->right = NULL;

                k--;
                if (k == 0)
                {
                    ans = curr->data;
                }

                curr = curr->right;
            }
        }
        else
        {
            k--;
            if (k == 0)
            {
                ans = curr->data;
            }
            curr = curr->right;
        }
    }
    return ans;
}