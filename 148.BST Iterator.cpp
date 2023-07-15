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

class BSTiterator
{
private:
    stack<TreeNode<int> *> s;
    void pushLeft(TreeNode<int> *root)
    {
        s.push(root);
        while (root->left)
        {
            s.push(root->left);
            root = root->left;
        }
    }

public:
    BSTiterator(TreeNode<int> *root)
    {
        pushLeft(root);
    }

    int next()
    {
        TreeNode<int> *temp = s.top();
        s.pop();
        if (temp->right)
            pushLeft(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/