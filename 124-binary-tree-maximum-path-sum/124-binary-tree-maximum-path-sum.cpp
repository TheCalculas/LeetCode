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
    int sum = INT_MIN;
    int h(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l = h(root->left);
        int r = h(root->right);
        l = max(0, l);
        r = max(0, r);
        sum = max(sum, root->val + l + r);
        return root->val + max(l, r);
        
    }
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        h(root);
        return sum;
    }
};