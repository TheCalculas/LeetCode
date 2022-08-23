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
    bool flag = false;
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        int l = f(root->left);
        int r = f(root->right);
        if(abs(l-r)>1) flag = true;
        return max(l, r) +1;
    }
    bool isBalanced(TreeNode* root) {
        flag = false;
        f(root);
        return !flag;
    }
};