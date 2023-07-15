#include <bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public :
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode<int> *root)
{

    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *curr = root;
    q.push(curr);

    while (!q.empty())
    {
        int sz = q.size();
        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode<int> *frontNode = q.front();
            q.pop();
            if (i + 1 < sz)
            {
                BinaryTreeNode<int> *nextNode = q.front();
                frontNode->next = nextNode;
            }
            else
            {
                frontNode->next = NULL;
            }

            if (frontNode->left)
                q.push(frontNode->left);
            if (frontNode->right)
                q.push(frontNode->right);
        }
    }
}