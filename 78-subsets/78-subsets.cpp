class Solution
{
    public:
        void f(vector<int> nums, int i, int n, vector<int> cur, vector< vector< int>> &res)
        {
            if (i == n)
            {
                res.push_back(cur);
                return;
            }
            else {
                // take or notTake
                // take
                cur.push_back(nums[i]);
                f(nums, i+1, n, cur, res);
                cur.pop_back();
                f(nums, i+1, n, cur, res);
            }
        }
    vector<vector < int>> subsets(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        f(nums, 0, n, cur, res);
        return res;
    }
};