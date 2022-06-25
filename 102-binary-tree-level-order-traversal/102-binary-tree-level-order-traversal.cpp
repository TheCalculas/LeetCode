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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        vector<vector<int>> store;
        q.push(root);
        while(q.size())
        {
            vector<int> v;
            int n = q.size();
            while(n--)
            {
                auto t = q.front();
                q.pop();
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                v.push_back(t->val);
            }
            store.push_back(v);
        }
        return store;
    }
};