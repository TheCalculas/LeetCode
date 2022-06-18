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
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        TreeNode* root = new TreeNode(0);
        
        if(root1&&root2) root->val = root1->val + root2->val;
        else if(root1&&!root2) root->val = root1->val;
        else if(!root1&&root2) root->val = root2->val;
        else return NULL;
        root->left = mergeTrees((root1)?root1->left:NULL, (root2)?root2->left:NULL);
        root->right = mergeTrees((root1)?root1->right:NULL, (root2)?root2->right:NULL);
        return root;
    }
};