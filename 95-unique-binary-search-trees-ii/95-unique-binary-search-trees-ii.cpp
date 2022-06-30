class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return subTrees(1, n);
    }
private:
    vector<TreeNode*> subTrees(int start, int end){
        vector<TreeNode*> res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int i=start; i<=end; i++){
            vector<TreeNode*> left = subTrees(start, i-1);
            vector<TreeNode*> right = subTrees(i+1, end);
            for(TreeNode* l: left){
                for(TreeNode* r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};