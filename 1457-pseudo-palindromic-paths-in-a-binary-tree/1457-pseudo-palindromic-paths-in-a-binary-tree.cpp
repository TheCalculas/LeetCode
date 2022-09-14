/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution {
    int solve(TreeNode *root, int freq[]) {
        if (root == nullptr) {
            return 0;
        }
        
        freq[root->val]++;
        if (root->left == nullptr && root->right == nullptr) {
            int count = 0;
            for (int i = 0; i <= 9; i++) {
                if ((freq[i] & 1) != 0) {
                    count++;
                }
            }
            freq[root->val]--;
            return (count <= 1) ? 1 : 0;
        }
        
        int ans = solve(root->left, freq) + solve(root->right, freq);
        freq[root->val]--;
        return ans;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        int freq[10] = {0};
        return solve(root, freq);
    }
};