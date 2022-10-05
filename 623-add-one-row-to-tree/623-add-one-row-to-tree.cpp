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
    void creation(TreeNode* root, int val)
    {
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        TreeNode* n = new TreeNode(val);
        n->left = l;
        n->right = NULL;
        root->left = n;
        
        TreeNode* h = new TreeNode(val);
        h->right = r;
        h->left = NULL;
        root->right = h;
    }
    void travel(TreeNode* root, int depth, int val)
    {
        if(root==NULL) return;
        if(depth==1){
            creation(root, val);
            return;
        }
        travel(root->left, depth-1, val);
        travel(root->right, depth-1, val);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode* res = new TreeNode(val);
            res->left = root;
            return res;
        }
        travel(root, depth-1, val);
        return root;
    }
};