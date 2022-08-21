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
    vector<int> num;
    void dfs(TreeNode* root, string cur)
    {
        if(root==NULL) return;
        else if(root->left==NULL&&root->right==NULL)
        {
            cur.push_back(root->val+'0');
            num.push_back(stoi(cur));
            cur.pop_back();
            return;
        }
        else{
            cur.push_back(root->val+'0');
            dfs(root->left, cur);
            dfs(root->right, cur);
            cur.pop_back();
        }
    }
    int sumNumbers(TreeNode* root) {
        string cur ="";
        dfs(root, cur);
        return accumulate(num.begin(), num.end(), 0);
    }
};