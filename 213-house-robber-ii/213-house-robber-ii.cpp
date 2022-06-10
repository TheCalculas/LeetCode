class Solution {
public:
      int t[101];
    int solve(vector<int> &nums,int i,int n)
    {
        if(i>=n)
            return 0;
        if(t[i]!=-1)
            return t[i];
        
        return t[i]= max(nums[i]+solve(nums,i+2,n),solve(nums,i+1,n));
    }
    int rob(vector<int>& nums) {
         
        if(nums.size()==1) return nums[0];
        
        memset(t,-1,sizeof(t));
        int a=solve(nums,0,nums.size()-1);
        memset(t,-1,sizeof(t));
        return max(a,solve(nums,1,nums.size()));
    }
};