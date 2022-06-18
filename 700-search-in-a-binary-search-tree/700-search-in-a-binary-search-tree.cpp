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
    TreeNode* ans = new TreeNode(0);
    bool flag = false;
    void helper(TreeNode* root, int val)
    {
        if(root==NULL||flag) return;
        if(root->val==val) {
            ans = root;
            flag = true;
            return;
        }
        if(root->val<val)
        {
            helper(root->right, val);
        }
        if(root->val>val) helper(root->left, val);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        helper(root, val);
        if(flag) return ans;
        return NULL;
    }
};