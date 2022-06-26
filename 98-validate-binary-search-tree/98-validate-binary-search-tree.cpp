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
    
    vector<int> v;
    void helper(TreeNode* root)
    {
        if(root==NULL) return;
        helper(root->left);
        v.push_back(root->val);
        helper(root->right);
    }
    bool isValidBST(TreeNode* root) {
        helper(root);
        bool flag = true;
        vector<int> vv = v;
        set<int> s;
        for(auto x:v)
            s.insert(x);
        if(s.size()!=v.size())return false;
        sort(vv.begin(), vv.end());
        if(vv==v)
            return true;
        return false;
    }
};