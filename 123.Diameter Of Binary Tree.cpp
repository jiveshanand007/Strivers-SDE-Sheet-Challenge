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
pair<int, int> diameterHeight(TreeNode<int> *root)
{
    if (!root)
    {
        return {0, 0};
    }

    pair<int, int> left = diameterHeight(root->left);
    pair<int, int> right = diameterHeight(root->right);

    int option1 = left.first;
    int option2 = right.first;
    int option3 = left.second + 1 + right.second; // height(left)+height(right)+rootNode
    pair<int, int> ans;
    ans.first = max(option1, max(option2, option3)); // Diameter calculation
    ans.second = max(left.second, right.second) + 1; // Height calculation
    return ans;
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    return diameterHeight(root).first - 1;
}
