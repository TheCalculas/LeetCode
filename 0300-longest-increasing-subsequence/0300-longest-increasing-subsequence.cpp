class Solution {
public:
    int f(vector<int>& v, int idx, int pre_idx, vector<vector<int>>&dp)
    {
        if(idx==v.size()+1) return 0;
        if(dp[idx][pre_idx]!=-1) return dp[idx][pre_idx];
        int len = 0 + f(v, idx+1, pre_idx, dp);
        if(pre_idx==0||v[idx-1]>v[pre_idx-1])
        {
            return dp[idx][pre_idx] = max(len, 1 + f(v, idx+1, idx, dp));
        }
        return dp[idx][pre_idx] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, -1));
        return f(nums, 1, 0, dp);
    }
};