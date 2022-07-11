
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