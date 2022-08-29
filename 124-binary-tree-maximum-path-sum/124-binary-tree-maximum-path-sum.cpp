/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int f(TreeNode* root, int &sum)
    {
        if(root == NULL) return 0;
        int l = f(root->left, sum);
        int r = f(root->right, sum);
        l = max(l, 0);
        r = max(r, 0);
        int a = root->val + l + r;
        sum = max(sum, a);
        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        f(root, sum);
        return sum;
    }
};