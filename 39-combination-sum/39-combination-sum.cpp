class Solution {
public:
    void f(vector<int> given, int target, int i, int n, vector<int> curr, vector<vector<int>> &res)
    {
        if(target==0)
        {
            res.push_back(curr);
            return;
        }
        if(i==n)
        {            
            return;
        }
        else{
            if(given[i]<=target)
            {
                // take
                curr.push_back(given[i]);
                f(given, target - given[i], i, n, curr, res);
                curr.pop_back();
            }
            f(given, target, i+1, n, curr, res);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        int n = c.size();
        vector<int> curr;
        vector<vector<int>> res;
        f(c, target, 0, n, curr, res);
        return res;
    }
};