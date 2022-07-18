class Solution {
public:
      int solve(vector<int>&nums,int target,map<pair<int,int>,int>&dp,int i,int val){
       if(i==nums.size()){
           if(target==val){return 1;}
           return 0;
       }
        if(dp.count({i,val})) return dp[{i,val}];
        int pos = solve(nums,target,dp,i+1,val+nums[i]);
        int neg = solve(nums,target,dp,i+1,val-nums[i]);
        return dp[{i,val}] = pos+neg;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        map<pair<int,int>,int>dp;
        return solve(nums,target,dp,0,0);
    }
};