class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // previous ko acount mei lelo
        int n = nums.size();
        vector<int> dp(n+1, 1);
        vector<int> hash(n+1, -1);
        int mx = 1;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[j]<nums[i]&&dp[i]<dp[j]+1)
                {
                    dp[i] = 1 + dp[j];
                    mx = max(mx, dp[i]); 
                }
            }
            
        }
        return mx;
    }
};