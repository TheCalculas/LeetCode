class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int kaden = nums[0];
        int mx = nums[0];
        for(int i = 1; i<nums.size(); i++)
        {
             if(kaden<0)
                kaden = 0;
            int x = nums[i];
            kaden+= x;
           
            mx = max(mx, kaden);
        }
        return mx;
    }
};