class Solution {
public:
    
    int f(vector<int> &nums, int prev_idx, int idx)
    {
        if(idx==nums.size())
        {
            return 0;
        }
        int notTake = 0 + f(nums, prev_idx, idx+1);  
        int take = 0;
        if(prev_idx==-1||nums[prev_idx]<nums[idx])
        {
            take = 1 + f(nums, idx, idx+1);
        }
        return max(take, notTake);
    }
    
    int lengthOfLIS(vector<int>& arr) {
        // return f(nums, -1, 0);
        int n = arr.size();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
        for(int ind = n-1; ind>=0; ind --){
            for (int prev_index = ind-1; prev_index >=-1; prev_index --){

                int notTake = 0 + dp[ind+1][prev_index +1];

                int take = 0;

                if(prev_index == -1 || arr[ind] > arr[prev_index]){

                    take = 1 + dp[ind+1][ind+1];
                }

                dp[ind][prev_index+1] = max(notTake,take);

            }
        }

        return dp[0][0];
        
    }
};