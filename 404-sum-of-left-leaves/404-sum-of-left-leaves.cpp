/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        void helper(TreeNode *root, int &sum, int indicator)
        {
            if (root == NULL) return;
            if (indicator==-1&&(root->left==NULL&&root->right==NULL))
            {
                sum += root->val;
            }
            helper(root->left, sum, -1);
            helper(root->right, sum, +1);
        }
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        int indicator = 0;
        // 0 for root
        // 1 for right 
        // -1 for left
        helper(root, sum, indicator);
        return sum;
    }
};