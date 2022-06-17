/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {
            if (root == NULL) return {};
            queue<TreeNode*> q;
            q.push(root);
            vector<int> v;
            while (q.size())
            {
                int n = q.size();
                
                while (n--)
                {
                    auto hehe = q.front();
                    q.pop();
                    if (hehe->left) q.push(hehe->left);
                    if (hehe->right) q.push(hehe->right);
                    if (n == 0) v.push_back(hehe->val);
                    
                }
            }
            return v;
        }
};