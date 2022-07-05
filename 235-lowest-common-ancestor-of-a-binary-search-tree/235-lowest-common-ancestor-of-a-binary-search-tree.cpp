/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int a = p->val;
        int b = q->val;
        int mn = min(a, b);
        int mx = max(a, b);
        while(root)
        {
            if(root->val<mn)
            {
                if(root->right)root=root->right;
                
            }
            else if(root->val>mx)
            {
                if(root->left) root = root->left;
            }
            else if(root->val<mx&&root->val>mn) return root;
            
            else if(root->val==mn||root->val==mx) return root;
        }
        return root;
    }
};