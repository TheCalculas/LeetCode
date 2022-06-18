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
    int height(TreeNode* root, int &dia)
    {
        if(root==NULL) return 0;
        int lefDia = height(root->left, dia);
        int rigDia = height(root->right, dia);
        dia = max(dia,lefDia+rigDia); // as the max dia is the max of right and left
        return max(lefDia, rigDia)+1; // returns the max height
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        height(root, dia);
        return dia;
    }
    
};