class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int sum = 0;
        int mxsum = INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(sum<0) sum = 0;
            sum+=nums[i];
            mxsum = max(mxsum, sum);
        
        }
        return mxsum;
    }
};