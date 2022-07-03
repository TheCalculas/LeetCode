class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int positive = 1;
        int negative = 1;
        for(int i=1; i<n; i++)
        {
            if(nums[i]-nums[i-1]>0)
                positive = negative+1;
            else if(nums[i]-nums[i-1]<0)
                negative = positive+ 1;
        }
        return max(positive, negative);
            
    }
};