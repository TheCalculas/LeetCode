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
    bool srch(TreeNode *root, int val, TreeNode *t){
        if(!root){
            return false;
        }
        if(root->val == val && root != t){
            return true;
        }
        bool l=false, r= false;
        if(val < root -> val){
            l = srch(root -> left,val,t);
        }
        else if(val > root -> val){
            l = srch(root->right,val,t);
        }
        return (l || r);
    }
    void pre(TreeNode *root,TreeNode *r, int k, bool &ans){
        if(!root || ans==true){
            return;
        }
        if( srch(r,k - root->val,root) == true){
            ans=true;
            return;
        }
        pre(root->left,r,k,ans);
        pre(root->right,r,k,ans);
    }
    bool findTarget(TreeNode* root, int k) {
        bool ans= false;
        pre(root,root,k,ans);
        return ans;
    }
};