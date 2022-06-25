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
    bool isSame(TreeNode* root1, TreeNode* root2)
    {
        // kabhi bhi null pointer aur non defined data ko access mat karna error aayega
        
        if(root1==NULL&&root2==NULL)
            return true;
        if(root1!=NULL&&root2!=NULL){
        if((root1->val==root2->val)&&(root1->left==NULL&&root1->right==NULL)&&(root2->right==NULL&&root2->left==NULL))
            return true;
        if((root1->val == root2->val)&&isSame(root1->left, root2->right)&&isSame(root1->right, root2->left))
           return true;}
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return(isSame(root->left, root->right));
    }
};