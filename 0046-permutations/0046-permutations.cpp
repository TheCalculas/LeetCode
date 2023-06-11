class Solution {
public:
    void f(vector<int>& v, int idx, vector<vector<int>> &res)
    {
        if(idx==v.size())
        {
            res.push_back(v);
            return;
        }
        
        for(int i = idx; i<v.size(); i++)
        {
            swap(v[i], v[idx]);
            f(v, idx+1, res);
            swap(v[i], v[idx]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> res;
        f(v, 0, res);
        return res;
    }
};