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
    
    void f(TreeNode* root, map<int, map<int, multiset<int>>> &mp, int x, int y)
    {
        if(root==NULL) return;
        mp[x][y].insert(root->val);
        f(root->left, mp, x-1, y+1);
        f(root->right, mp, x+1, y+1);
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        // int idx = 0;
        int x = 0;
        int y = 0;
        
        f(root, mp, x, y);
        vector<vector<int>> v;
        for(auto x: mp)
        {
            vector<int> temp;
            for(auto y: x.second)
            {
                for(auto z: y.second) temp.push_back(z);
            }
            v.push_back(temp);
        }
        return v;
    }
};