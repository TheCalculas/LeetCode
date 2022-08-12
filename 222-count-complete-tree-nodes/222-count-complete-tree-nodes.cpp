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
    int getLeftHeight(TreeNode* root) {
        int height = 0;
        while(root) { 
            root = root->left;
            height++;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if(!root) return 0;

        int lh = getLeftHeight(root->left);
        int rh = getLeftHeight(root->right);

        if(lh == rh) 
            return pow(2,lh) + countNodes(root->right);

        return pow(2,rh) + countNodes(root->left);
    }
};