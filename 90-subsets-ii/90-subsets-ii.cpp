class Solution {
public:
    set<vector<int>> s;
    void f(vector<int> nums, int i, int n, vector<int> cur, vector< vector< int>> &res)
        {
            if (i == n)
            {
                s.insert(cur);
                res.push_back(cur);
                return;
            }
            else {
                // take or notTake
                // take make sure that you dont store dublicates
                cur.push_back(nums[i]);
                f(nums, i+1, n, cur, res);
                cur.pop_back();
                f(nums, i+1, n, cur, res);
            }
        }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        f(nums, 0, n, cur, res);
        // return s;?
        vector<vector<int>> ff;
        for(auto x: s)
        {
            ff.push_back(x);
        }
        return ff;
    }
};