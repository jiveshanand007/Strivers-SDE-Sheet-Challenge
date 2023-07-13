#include <bits/stdc++.h>
/************************************************************

    Following is the Tree node structure

    template <typename T>
    class TreeNode
    {
        public :
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val)
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include <bits/stdc++.h>
long long int findMaxSum(TreeNode<int> *root, long long int &ans, int &cnt)
{
    if (!root)
        return 0;
    if (!root->right && !root->left)
        cnt++;
    long long int leftMax = max(0LL, findMaxSum(root->left, ans, cnt));
    long long int rightMax = max(0LL, findMaxSum(root->right, ans, cnt));
    long long int val = (long long int)root->val;
    ans = max(ans, (leftMax + rightMax) + val);
    return max(leftMax, rightMax) + val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    long long int ans = LLONG_MIN;
    int cnt = 0;
    findMaxSum(root, ans, cnt);
    return cnt <= 1 ? -1 : ans;
}