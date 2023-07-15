#include <bits/stdc++.h>
/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
class BSTIterator
{
private:
    stack<BinaryTreeNode<int> *> s;
    bool reverse = true;
    void pushLeft(BinaryTreeNode<int> *root)
    {
        while (root)
        {
            s.push(root);
            if (!reverse)
                root = root->left;
            else
                root = root->right;
        }
    }

public:
    BSTIterator(BinaryTreeNode<int> *root, bool isReverse)
    {
        reverse = isReverse;
        pushLeft(root);
    }
    bool isEmpty()
    {
        return s.empty();
    }
    int next()
    {
        BinaryTreeNode<int> *temp = s.top();
        s.pop();
        if (!reverse)
            pushLeft(temp->right);
        else
            pushLeft(temp->left);
        return temp->data;
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return false;
    BSTIterator left(root, false);
    BSTIterator right(root, true);
    bool ans = false;

    int i = left.next();
    int j = right.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j > k)
            j = right.next();
        else
            i = left.next();
    }
    return false;
}